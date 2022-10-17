//
//  BLBLEConfigManager.h
//  BLBLEConfigApi
//
//  Created by dev on 2021/7/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    kBLESuccess,
    kBLENotAccess,
    kBLEInputError,
    kBLETimeOut,
    kBLEONConfig
} BLConfigErrorEnum;

typedef enum : NSUInteger {
    BLE_DEV_STATE_IDLE = 0,                 // 待配网状态
    BLE_DEV_STATE_CONFIG,                   // 收到配置命令
    BLE_DEV_STATE_CONNECTING_AP,            // 开始连接WiFi
    BLE_DEV_STATE_CONNECTED_AP,             // WiFi连接成功
    BLE_DEV_STATE_CONNECTED_CLOUD           // 服务器连接成功
} BLConfigStateEnum;

@protocol BLBLEConfigManagerDelegate <NSObject>

@optional
/// 蓝牙配网结果
/// @param result 配置结果
- (void)onConfigResult:(NSDictionary *_Nullable)result;

@end


@interface BLBLEConfigManager : NSObject

+ (instancetype)sharedManager;

/**
 *  代理
 */
@property (nonatomic, weak) id <BLBLEConfigManagerDelegate> _Nullable delegate;

/// 开启设备上报信息接收服务
- (void)startBleReceiveService;

/// 关闭设备上报信息接收服务
- (void)stopBleReceiveService;

/// 开始配网
- (int)startDeviceConfigWithInfo:(NSDictionary *)info andTimeout:(double)timeout;

/// 结束配网
- (int)stopDeviceConfig;


@end

NS_ASSUME_NONNULL_END
