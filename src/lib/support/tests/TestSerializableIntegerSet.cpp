/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include <support/CHIPMem.h>
#include <support/CHIPMemString.h>
#include <support/SerializableIntegerSet.h>
#include <support/UnitTestRegistration.h>

#include <nlunit-test.h>

namespace {

void TestSerializableIntegerSet(nlTestSuite * inSuite, void * inContext)
{
    chip::SerializableU64Set<8> set;
    NL_TEST_ASSERT(inSuite, !set.Contains(123));

    NL_TEST_ASSERT(inSuite, set.Insert(123) == CHIP_NO_ERROR);
    NL_TEST_ASSERT(inSuite, set.Contains(123));

    NL_TEST_ASSERT(inSuite, set.Insert(123) == CHIP_NO_ERROR);
    NL_TEST_ASSERT(inSuite, set.Contains(123));

    set.Remove(123);
    NL_TEST_ASSERT(inSuite, !set.Contains(123));

    for (uint64_t i = 1; i <= 8; i++)
    {
        NL_TEST_ASSERT(inSuite, set.Insert(i) == CHIP_NO_ERROR);
    }

    NL_TEST_ASSERT(inSuite, set.Insert(9) != CHIP_NO_ERROR);

    for (uint64_t i = 1; i <= 8; i++)
    {
        NL_TEST_ASSERT(inSuite, set.Contains(i));
    }

    size_t size = set.SerializedSize();
    NL_TEST_ASSERT(inSuite, set.MaxSerializedSize() == size);

    for (uint64_t i = 1; i <= 7; i++)
    {
        set.Remove(i);
        NL_TEST_ASSERT(inSuite, set.SerializedSize() == size);
    }

    set.Remove(8);
    NL_TEST_ASSERT(inSuite, set.SerializedSize() == CHIP_MAX_SERIALIZED_SIZE_U64(0));
}

void TestSerializableIntegerSetNonZero(nlTestSuite * inSuite, void * inContext)
{
    chip::SerializableU64Set<8, 2> set;
    NL_TEST_ASSERT(inSuite, !set.Contains(123));

    NL_TEST_ASSERT(inSuite, set.Insert(123) == CHIP_NO_ERROR);
    NL_TEST_ASSERT(inSuite, set.Contains(123));

    NL_TEST_ASSERT(inSuite, set.Insert(123) == CHIP_NO_ERROR);
    NL_TEST_ASSERT(inSuite, set.Contains(123));

    set.Remove(123);
    NL_TEST_ASSERT(inSuite, !set.Contains(123));

    for (uint64_t i = 0; i <= 1; i++)
    {
        NL_TEST_ASSERT(inSuite, set.Insert(i) == CHIP_NO_ERROR);
    }

    // Try inserting empty value
    NL_TEST_ASSERT(inSuite, set.Insert(2) != CHIP_NO_ERROR);

    for (uint64_t i = 3; i <= 7; i++)
    {
        NL_TEST_ASSERT(inSuite, set.Insert(i) == CHIP_NO_ERROR);
    }

    for (uint64_t i = 0; i <= 1; i++)
    {
        NL_TEST_ASSERT(inSuite, set.Contains(i));
    }

    for (uint64_t i = 3; i <= 7; i++)
    {
        NL_TEST_ASSERT(inSuite, set.Contains(i));
    }

    for (uint64_t i = 0; i <= 6; i++)
    {
        set.Remove(i);
    }

    set.Remove(7);
    NL_TEST_ASSERT(inSuite, set.SerializedSize() == CHIP_MAX_SERIALIZED_SIZE_U64(0));
}

void TestSerializableIntegerSetSerialize(nlTestSuite * inSuite, void * inContext)
{
    chip::SerializableU64Set<8> set;

    for (uint64_t i = 1; i <= 6; i++)
    {
        NL_TEST_ASSERT(inSuite, set.Insert(i) == CHIP_NO_ERROR);
    }

    char * buf    = nullptr;
    uint16_t size = 0;

    NL_TEST_ASSERT(inSuite, set.SerializeBase64(buf, size) == nullptr);
    NL_TEST_ASSERT(inSuite, size != 0);

    chip::Platform::ScopedMemoryString buf1("", size);
    NL_TEST_ASSERT(inSuite, set.SerializeBase64(buf1.Get(), size) == buf1.Get());
    NL_TEST_ASSERT(inSuite, size != 0);

    uint16_t size2 = static_cast<uint16_t>(2 * size);
    chip::Platform::ScopedMemoryString buf2("", size2);
    NL_TEST_ASSERT(inSuite, set.SerializeBase64(buf2.Get(), size2) == buf2.Get());
    NL_TEST_ASSERT(inSuite, size2 == size);

    chip::SerializableU64Set<8> set2;
    NL_TEST_ASSERT(inSuite, set2.DeserializeBase64(buf2.Get(), size2) == CHIP_NO_ERROR);

    for (uint64_t i = 1; i <= 6; i++)
    {
        NL_TEST_ASSERT(inSuite, set.Contains(i));
    }
    NL_TEST_ASSERT(inSuite, !set.Contains(7));
}

int Setup(void * inContext)
{
    CHIP_ERROR error = chip::Platform::MemoryInit();
    if (error != CHIP_NO_ERROR)
        return FAILURE;
    return SUCCESS;
}

int Teardown(void * inContext)
{
    chip::Platform::MemoryShutdown();
    return SUCCESS;
}

} // namespace

#define NL_TEST_DEF_FN(fn) NL_TEST_DEF("Test " #fn, fn)
/**
 *   Test Suite. It lists all the test functions.
 */
static const nlTest sTests[] = {
    NL_TEST_DEF_FN(TestSerializableIntegerSet),          //
    NL_TEST_DEF_FN(TestSerializableIntegerSetNonZero),   //
    NL_TEST_DEF_FN(TestSerializableIntegerSetSerialize), //
    NL_TEST_SENTINEL()                                   //
};

int TestSerializableIntegerSet(void)
{
    nlTestSuite theSuite = { "CHIP SerializableIntegerSet tests", &sTests[0], Setup, Teardown };

    // Run test suit againt one context.
    nlTestRunner(&theSuite, nullptr);
    return nlTestRunnerStats(&theSuite);
}

CHIP_REGISTER_TEST_SUITE(TestSerializableIntegerSet)
