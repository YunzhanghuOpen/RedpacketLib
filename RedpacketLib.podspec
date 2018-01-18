Pod::Spec.new do |s|
  s.name             = 'RedpacketLib'
  s.version          = '3.5.3'
  s.summary          = 'RedpacketSDK'
  s.description      = <<-DESC
                       RedpacketSDK, allow you to send redpacket in your project.
                       * Redpacket
                       * Alipay
                       * 支付宝支付
                       * 红包SDK
                       * 发红包
                       DESC

  s.homepage         = 'http://yunzhanghu.com'
  s.license          = { :type => 'MIT', :file => "LICENSE" }
  s.author           = { 'Mr.Yang' => 'tonggang.yang@yunzhanghu.com' }
  s.source           = { :git => 'https://github.com/YunzhanghuOpen/cocoapods-RedpacketLib.git', :tag => "#{s.version}" }

  s.platform     = :ios, '8.0'
  s.requires_arc = true

  s.xcconfig     = {'OTHER_LDFLAGS' => '-ObjC'}
  s.vendored_libraries = 'RedpacketStaticLib/lib/*.a'
  s.source_files = 'RedpacketStaticLib/*.{h,m}'
  s.public_header_files = 'RedpacketStaticLib/*.h'
  s.resources = ['RedpacketStaticLib/resources/*.bundle']
  s.frameworks = 'AudioToolbox', 'CFNetwork'
  #s.resource = “redpacket.bundle"
  s.documentation_url = 'https://new.yunzhanghu.com/'
  s.dependency 'RedPacketAlipay'
end
