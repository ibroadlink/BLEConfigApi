Pod::Spec.new do |s|

  s.name         = "BLEConfigApi"
  s.version      = "2.2"
  s.authors      = { 'zjjllj@gmail.com' => 'zjjllj@gmail.com' }
  s.homepage     = "http://www.broadlink.com.cn"
  s.summary      = "broadlink蓝牙组件"
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.source       = { :git => 'https://github.com/ibroadlink/appsdk.git', :tag => s.version.to_s }
  s.platform     = :ios,'10.0'
  s.ios.deployment_target = '10.0'

  s.user_target_xcconfig = { 'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES' }
  s.frameworks   = 'UIKit', 'CoreBluetooth', 'Foundation'
  s.vendored_frameworks = '/BLEConfigApi/Classes/*.{framework}'

end