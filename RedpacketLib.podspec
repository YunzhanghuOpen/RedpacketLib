Pod::Spec.new do |s|
  s.name             = 'RedpacketLib'
  s.version          = '3.1.5'
  s.summary          = 'RedpacketSDK'
  s.description      = <<-DESC
                       RedpacketSDK, allow you to send redpacket in your project.
                       * Redpacket
                       * Alipay
                       * 支付宝支付
                       * 红包SDK
                       DESC

  s.homepage         = 'http://yunzhanghu.com'
  s.license          = { :file => "LICENSE" }
  s.author           = { 'Mr.Yang' => 'tonggang.yang@yunzhanghu.com' }
  s.source           = { :git => 'https://github.com/yunzhanghuOpen/RedpacketLib.git', :tag => '3.1.3' }

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.vendored_libraries = 'RedpacketStaticLib/lib/*.a'
  #s.source_files = 'RedpacketStaticLib/*.{h,m}'
  s.public_header_files = 'RedpacketStaticLib/*.h'
  s.resources = ['RedpacketStaticLib/resources/*.bundle']
  s.frameworks = 'AudioToolbox'
  #s.resource = “redpacket.bundle"
  s.documentation_url = 'http://yunzhanghu-com.oss-cn-qdjbp-a.aliyuncs.com/%E4%BA%91%E8%B4%A6%E6%88%B7%E7%BA%A2%E5%8C%85SDK%E6%8E%A5%E5%85%A5%E6%8C%87%E5%8D%97%28iOS%29%20v3_1_2.pdf'

  s.subspec 'Alipay' do |ali|
  ali.vendored_libraries = 'RedpacketStaticLib/Alipay/lib/*.a'
  #ali.source_files = 'RedpacketStaticLib/Alipay/*.{h,m}'
  ali.public_header_files = 'RedpacketStaticLib/Alipay/*.h'
  ali.resources = ['RedpacketStaticLib/Alipay/resources/*.bundle']
  ali.frameworks = 'CoreMotion'


end
