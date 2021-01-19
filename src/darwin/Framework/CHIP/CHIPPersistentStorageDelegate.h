/**
 *
 *    Copyright (c) 2020 Project CHIP Authors
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

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^SendKeyValue)(NSString * key, NSString * value);
typedef void (^CHIPSendSetStatus)(NSString * key, NSError * status);
typedef void (^CHIPSendDeleteStatus)(NSString * key, NSError * status);

/**
 * The protocol definition for the CHIPPersistenStorageDelegate
 *
 * All delegate methods will be called on the supplied Delegate Queue.
 */
@protocol CHIPPersistentStorageDelegate <NSObject>
@required

/**
 * Get the value for the given key
 *
 */
- (void)CHIPGetKeyValue:(NSString *)key handler:(SendKeyValue)completionHandler;

/**
 * Get the value for the given key
 *
 */
- (NSString *)CHIPGetKeyValue:(NSString *)key;

/**
 * Set the value of the key to the given value
 *
 */
- (void)CHIPSetKeyValue:(NSString *)key value:(NSString *)value handler:(CHIPSendSetStatus)completionHandler;

/**
 * Delete the key and corresponding value
 *
 */
- (void)CHIPDeleteKeyValue:(NSString *)key handler:(CHIPSendDeleteStatus)completionHandler;

@end

NS_ASSUME_NONNULL_END
