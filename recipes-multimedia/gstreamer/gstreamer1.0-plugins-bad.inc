require gstreamer1.0-plugins.inc

LICENSE = "GPLv2+ & LGPLv2+ & LGPLv2.1+ "

DEPENDS += "gstreamer1.0-plugins-base bzip2"

S = "${WORKDIR}/gst-plugins-bad-${PV}"

inherit gettext


PACKAGECONFIG ??= " \
    curl eglgles wayland uvch264 directfb neon \
    hls sbc dash bz2 smoothstreaming bluez \
    "
# rsvg requires librsvg >= 2.36
# dash = Dynamic Adaptive Streaming over HTTP
PACKAGECONFIG[assrender]       = "--enable-assrender,--disable-assrender,libass"
PACKAGECONFIG[curl]            = "--enable-curl,--disable-curl,curl"
PACKAGECONFIG[eglgles]         = "--enable-eglgles,--disable-eglgles,virtual/egl virtual/libgles2"
PACKAGECONFIG[faad]            = "--enable-faad,--disable-faad,faad2"
PACKAGECONFIG[libmms]          = "--enable-libmms,--disable-libmms,libmms"
PACKAGECONFIG[modplug]         = "--enable-modplug,--disable-modplug,libmodplug"
PACKAGECONFIG[mpg123]          = "--enable-mpg123,--disable-mpg123,mpg123"
PACKAGECONFIG[opus]            = "--enable-opus,--disable-opus,libopus"
PACKAGECONFIG[flite]           = "--enable-flite,--disable-flite,flite-alsa"
PACKAGECONFIG[opencv]          = "--enable-opencv,--disable-opencv,opencv"
PACKAGECONFIG[wayland]         = "--enable-wayland,--disable-wayland,wayland"
PACKAGECONFIG[uvch264]         = "--enable-uvch264,--disable-uvch264,libusb1 udev"
PACKAGECONFIG[directfb]        = "--enable-directfb,--disable-directfb,directfb"
PACKAGECONFIG[neon]            = "--enable-neon,--disable-neon,neon"
PACKAGECONFIG[openal]          = "--enable-openal,--disable-openal,openal-soft"
PACKAGECONFIG[rsvg]            = "--enable-rsvg,--disable-rsvg,librsvg"
PACKAGECONFIG[hls]             = "--enable-hls,--disable-hls,gnutls"
PACKAGECONFIG[sbc]             = "--enable-sbc,--disable-sbc,sbc"
PACKAGECONFIG[dash]            = "--enable-dash,--disable-dash,libxml2"
PACKAGECONFIG[bz2]             = "--enable-bz2,--disable-bz2,bzip2"
PACKAGECONFIG[fluidsynth]      = "--enable-fluidsynth,--disable-fluidsynth,fluidsynth"
PACKAGECONFIG[smoothstreaming] = "--enable-smoothstreaming,--disable-smoothstreaming,libxml2"
PACKAGECONFIG[bluez]           = "--enable-bluez,--disable-bluez,bluez4"

# unsupported in dylan:
# kate ladspa ofa wildmidi openjpeg webp daala opensl qtwrapper
# srtp wasapi winks winscreencap dts chromaprint resindvd faac
# gsm mimic mpeg2enc mplex pvr timidity teletextdec sdl sdltest
# sndfile soundtouch spc gme vdpau schro zbar rtmp spandsp

# these plugins have not been ported to 1.0 (yet):
#   directdraw vcd apexsink cdaudio dc1394 lv2 linsys musepack mythtv
#   nas timidity teletextdec sdl sndfile xvid wininet acm gsettings
#   sndio cdxaparse dccp faceoverlay hdvparse ivfparse jp2kdecimator
#   linsys mve nuvdemux osx_video patchdetect quicktime real sdi stereo
#   tta videomeasure videosignal vmnc

EXTRA_OECONF += " \
    --enable-dvb \
    --enable-shm \
    --enable-mfc \
    --enable-fbdev \
    --enable-decklink \
    --disable-directsound \
    --disable-wasapi \
    --disable-direct3d \
    --disable-directdraw \
    --disable-winscreencap \
    --disable-directshow \
    --disable-android_media \
    --disable-apple_media \
    --disable-osx_video \
    --disable-avc \
    --disable-quicktime \
    --disable-vcd \
    --disable-opensles \
    --disable-voamrwbenc \
    --disable-voaacenc \
    --disable-apexsink \
    --disable-cdaudio \
    --disable-chromaprint \
    --disable-dc1394 \
    --disable-webp \
    --disable-daala \
    --disable-dts \
    --disable-resindvd \
    --disable-faac \
    --disable-gsm \
    --disable-ladspa \
    --disable-lv2 \
    --disable-srtp \
    --disable-linsys \
    --disable-mimic \
    --disable-mpeg2enc \
    --disable-mplex \
    --disable-musepack \
    --disable-mythtv \
    --disable-nas \
    --disable-ofa \
    --disable-openjpeg \
    --disable-pvr \
    --disable-timidity \
    --disable-teletextdec \
    --disable-wildmidi \
    --disable-sdl \
    --disable-sdltest \
    --disable-sndfile \
    --disable-soundtouch \
    --disable-spc \
    --disable-gme \
    --disable-xvid \
    --disable-wininet \
    --disable-acm \
    --disable-vdpau \
    --disable-schro \
    --disable-zbar \
    --disable-rtmp \
    --disable-spandsp \
    --disable-gsettings \
    --disable-sndio \
    ${GSTREAMER_1_0_ORC} \
    "

ARM_INSTRUCTION_SET = "arm"

