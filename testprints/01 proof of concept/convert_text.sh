# convert -size 240x60 xc:none -font /usr/share/fonts/truetype/sazanami/sazanami-mincho.ttf -gravity center -fill green -draw "font-size 28 text 0,0 '装飾なしの普通の文字'" test1.png


convert -background white -fill black \
          -font ./SourceCodePro-Bold.otf -pointsize 200 label:A \
          -compress lzw \
          label.tif