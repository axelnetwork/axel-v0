#!/bin/bash
# create multiresolution windows icon
#mainnet
ICON_SRC=../../src/qt/res/icons/axel_utility_token.png
ICON_DST=../../src/qt/res/icons/axel_utility_token.ico
convert ${ICON_SRC} -resize 16x16 axel_utility_token-16.png
convert ${ICON_SRC} -resize 32x32 axel_utility_token-32.png
convert ${ICON_SRC} -resize 48x48 axel_utility_token-48.png
convert axel_utility_token-16.png axel_utility_token-32.png axel_utility_token-48.png ${ICON_DST}
#testnet
ICON_SRC=../../src/qt/res/icons/axel_utility_token_testnet.png
ICON_DST=../../src/qt/res/icons/axel_utility_token_testnet.ico
convert ${ICON_SRC} -resize 16x16 axel_utility_token-16.png
convert ${ICON_SRC} -resize 32x32 axel_utility_token-32.png
convert ${ICON_SRC} -resize 48x48 axel_utility_token-48.png
convert axel_utility_token-16.png axel_utility_token-32.png axel_utility_token-48.png ${ICON_DST}
rm axel_utility_token-16.png axel_utility_token-32.png axel_utility_token-48.png
