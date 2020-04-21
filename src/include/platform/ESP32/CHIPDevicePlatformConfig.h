/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *    Copyright (c) 2018 Nest Labs, Inc.
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

/**
 *    @file
 *          Platform-specific configuration overrides for the Chip Device Layer
 *          on the ESP32.
 */

#ifndef CHIP_DEVICE_PLATFORM_CONFIG_H
#define CHIP_DEVICE_PLATFORM_CONFIG_H

// ==================== Platform Adaptations ====================

#define CHIP_DEVICE_CONFIG_LWIP_WIFI_STATION_IF_NAME "st"

// ==================== Kconfig Overrides ====================

// The following values are configured via the ESP-IDF Kconfig mechanism.

#define CHIP_DEVICE_CONFIG_CHIP_TASK_STACK_SIZE CONFIG_CHIP_TASK_STACK_SIZE
#define CHIP_DEVICE_CONFIG_CHIP_TASK_PRIORITY CONFIG_CHIP_TASK_PRIORITY
#define CHIP_DEVICE_CONFIG_MAX_EVENT_QUEUE_SIZE CONFIG_MAX_EVENT_QUEUE_SIZE
#define CHIP_DEVICE_CONFIG_SERVICE_DIRECTORY_CACHE_SIZE CONFIG_SERVICE_DIRECTORY_CACHE_SIZE
#define CHIP_DEVICE_CONFIG_DEVICE_VENDOR_ID CONFIG_DEVICE_VENDOR_ID
#define CHIP_DEVICE_CONFIG_DEVICE_PRODUCT_ID CONFIG_DEVICE_PRODUCT_ID
#define CHIP_DEVICE_CONFIG_DEFAULT_DEVICE_PRODUCT_REVISION CONFIG_DEFAULT_DEVICE_PRODUCT_REVISION
#define CHIP_DEVICE_CONFIG_DEVICE_FIRMWARE_REVISION CONFIG_DEVICE_FIRMWARE_REVISION
#define CHIP_DEVICE_CONFIG_WIFI_STATION_RECONNECT_INTERVAL CONFIG_WIFI_STATION_RECONNECT_INTERVAL
#define CHIP_DEVICE_CONFIG_MAX_SCAN_NETWORKS_RESULTS CONFIG_MAX_SCAN_NETWORKS_RESULTS
#define CHIP_DEVICE_CONFIG_WIFI_SCAN_COMPLETION_TIMEOUT CONFIG_WIFI_SCAN_COMPLETION_TIMEOUT
#define CHIP_DEVICE_CONFIG_WIFI_CONNECTIVITY_TIMEOUT CONFIG_WIFI_CONNECTIVITY_TIMEOUT
#define CHIP_DEVICE_CONFIG_WIFI_AP_SSID_PREFIX CONFIG_WIFI_AP_SSID_PREFIX
#define CHIP_DEVICE_CONFIG_WIFI_AP_CHANNEL CONFIG_WIFI_AP_CHANNEL
#define CHIP_DEVICE_CONFIG_WIFI_AP_MAX_STATIONS CONFIG_WIFI_AP_MAX_STATIONS
#define CHIP_DEVICE_CONFIG_WIFI_AP_BEACON_INTERVAL CONFIG_WIFI_AP_BEACON_INTERVAL
#define CHIP_DEVICE_CONFIG_WIFI_AP_IDLE_TIMEOUT CONFIG_WIFI_AP_IDLE_TIMEOUT
#define CHIP_DEVICE_CONFIG_ENABLE_CHIPOBLE CONFIG_ENABLE_CHIPOBLE
#define CHIP_DEVICE_CONFIG_BLE_DEVICE_NAME_PREFIX CONFIG_BLE_DEVICE_NAME_PREFIX
#define CHIP_DEVICE_CONFIG_BLE_FAST_ADVERTISING_INTERVAL CONFIG_BLE_FAST_ADVERTISING_INTERVAL
#define CHIP_DEVICE_CONFIG_BLE_SLOW_ADVERTISING_INTERVAL CONFIG_BLE_SLOW_ADVERTISING_INTERVAL
#define CHIP_DEVICE_CONFIG_CHIPOBLE_SINGLE_CONNECTION CONFIG_CHIPOBLE_SINGLE_CONNECTION
#define CHIP_DEVICE_CONFIG_CHIPOBLE_DISABLE_ADVERTISING_WHEN_PROVISIONED CONFIG_CHIPOBLE_DISABLE_ADVERTISING_WHEN_PROVISIONED
#define CHIP_DEVICE_CONFIG_ENABLE_SERVICE_DIRECTORY_TIME_SYNC CONFIG_ENABLE_SERVICE_DIRECTORY_TIME_SYNC
#define CHIP_DEVICE_CONFIG_ENABLE_CHIP_TIME_SERVICE_TIME_SYNC CONFIG_ENABLE_CHIP_TIME_SERVICE_TIME_SYNC
#define CHIP_DEVICE_CONFIG_CHIP_TIME_SERVICE_ENDPOINT_ID CONFIG_CHIP_TIME_SERVICE_ENDPOINT_ID
#define CHIP_DEVICE_CONFIG_DEFAULT_TIME_SYNC_INTERVAL CONFIG_DEFAULT_TIME_SYNC_INTERVAL
#define CHIP_DEVICE_CONFIG_TIME_SYNC_TIMEOUT CONFIG_TIME_SYNC_TIMEOUT
#define CHIP_DEVICE_CONFIG_SERVICE_PROVISIONING_ENDPOINT_ID CONFIG_SERVICE_PROVISIONING_ENDPOINT_ID
#define CHIP_DEVICE_CONFIG_SERVICE_PROVISIONING_CONNECTIVITY_TIMEOUT CONFIG_SERVICE_PROVISIONING_CONNECTIVITY_TIMEOUT
#define CHIP_DEVICE_CONFIG_SERVICE_PROVISIONING_REQUEST_TIMEOUT CONFIG_SERVICE_PROVISIONING_REQUEST_TIMEOUT
#define CHIP_DEVICE_CONFIG_ENABLE_TEST_DEVICE_IDENTITY CONFIG_ENABLE_TEST_DEVICE_IDENTITY
#define CHIP_DEVICE_CONFIG_ENABLE_FIXED_TUNNEL_SERVER CONFIG_ENABLE_FIXED_TUNNEL_SERVER
#define CHIP_DEVICE_CONFIG_TUNNEL_SERVER_ADDRESS CONFIG_TUNNEL_SERVER_ADDRESS
#define CHIP_DEVICE_CONFIG_DISABLE_ACCOUNT_PAIRING CONFIG_DISABLE_ACCOUNT_PAIRING
#define CHIP_DEVICE_CONFIG_USE_TEST_PAIRING_CODE CONFIG_USE_TEST_PAIRING_CODE
#define CHIP_DEVICE_CONFIG_USE_TEST_SERIAL_NUMBER CONFIG_USE_TEST_SERIAL_NUMBER
#define CHIP_DEVICE_CONFIG_ENABLE_TRAIT_MANAGER CONFIG_ENABLE_TRAIT_MANAGER
#define CHIP_DEVICE_CONFIG_ENABLE_WIFI_TELEMETRY CONFIG_ENABLE_WIFI_TELEMETRY
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD_TELEMETRY CONFIG_ENABLE_THREAD_TELEMETRY
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD_TELEMETRY_FULL CONFIG_ENABLE_THREAD_TELEMETRY_FULL
#define CHIP_DEVICE_CONFIG_ENABLE_TUNNEL_TELEMETRY CONFIG_ENABLE_TUNNEL_TELEMETRY
#define CHIP_DEVICE_CONFIG_EVENT_LOGGING_CRIT_BUFFER_SIZE CONFIG_EVENT_LOGGING_CRIT_BUFFER_SIZE
#define CHIP_DEVICE_CONFIG_EVENT_LOGGING_PROD_BUFFER_SIZE CONFIG_EVENT_LOGGING_PROD_BUFFER_SIZE
#define CHIP_DEVICE_CONFIG_EVENT_LOGGING_INFO_BUFFER_SIZE CONFIG_EVENT_LOGGING_INFO_BUFFER_SIZE
#define CHIP_DEVICE_CONFIG_EVENT_LOGGING_DEBUG_BUFFER_SIZE CONFIG_EVENT_LOGGING_DEBUG_BUFFER_SIZE
#define CHIP_DEVICE_CONFIG_LOG_PROVISIONING_HASH CONFIG_LOG_PROVISIONING_HASH

#endif // CHIP_DEVICE_PLATFORM_CONFIG_H
