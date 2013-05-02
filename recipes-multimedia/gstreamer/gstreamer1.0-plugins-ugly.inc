require gstreamer1.0-plugins.inc

LICENSE = "GPLv2+ & LGPLv2.1+ & LGPLv2+"
LICENSE_FLAGS = "commercial"

DEPENDS += "gstreamer1.0-plugins-base libid3tag"

PR = "r1"

inherit gettext


PACKAGECONFIG ??= " \
    a52dec lame mad mpeg2dec \
    "

PACKAGECONFIG[a52dec]   = "--enable-a52dec,--disable-a52dec,liba52"
PACKAGECONFIG[cdio]     = "--enable-cdio,--disable-cdio,libcdio"
PACKAGECONFIG[dvdread]  = "--enable-dvdread,--disable-dvdread,libdvdread"
PACKAGECONFIG[lame]     = "--enable-lame,--disable-lame,lame"
PACKAGECONFIG[mad]      = "--enable-mad,--disable-mad,libmad"
PACKAGECONFIG[mpeg2dec] = "--enable-mpeg2dec,--disable-mpeg2dec,mpeg2dec"
PACKAGECONFIG[x264]     = "--enable-x264,--disable-x264,x264"


EXTRA_OECONF += " \
    --disable-amrnb \
    --disable-amrwb \
    --disable-sidplay \
    --disable-twolame \
    ${GSTREAMER_1_0_ORC} \
    "

do_configure_prepend() {
	# This m4 file contains nastiness which conflicts with libtool 2.2.2
	rm ${S}/m4/lib-link.m4 || true
}
