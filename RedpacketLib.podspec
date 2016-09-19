Pod::Spec.new do |s|  
  s.name             = 'RedpacketLib'
  s.version          = '3.1.4'
  s.summary          = 'RedpacketSDK'
  s.description      = <<-DESC  
                       RedpacketSDK, allow you to send redpacket in your project.
                       DESC
  s.homepage         = 'http://yunzhanghu.com'
  s.license          = { :type => "MIT", :file => "LICENSE" }
  s.author           = { 'Mr.Yang' => 'tonggang.yang@yunzhanghu.com' }  
  s.source           = { :git => 'https://github.com/yunzhanghuOpen/Redpacket_iOS.git', :tag => s.version.to_s }  
  
  s.platform     = :ios, '7.0'
  s.requires_arc = true
  
  s.vendored_libraries = 'RedpacketStaticLib/lib/*.a'
  s.source_files = 'RedpacketStaticLib/*.{h,m}'
  s.public_header_files = 'RedpacketStaticLib/*.h'
  s.resources = ['RedpacketStaticLib/resources/*.bundle']
  s.frameworks = 'Foundation', 'CoreGraphics', 'UIKit' 
  #s.resource = “redpacket.bundle"

end 
