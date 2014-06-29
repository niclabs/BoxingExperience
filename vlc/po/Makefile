# Makefile for PO directory in any package using GNU gettext.
# Copyright (C) 1995-1997, 2000-2007, 2009-2010 by Ulrich Drepper <drepper@gnu.ai.mit.edu>
#
# This file can be copied and used freely without restrictions.  It can
# be used in projects which are not available under the GNU General Public
# License but which still want to provide support for the GNU gettext
# functionality.
# Please note that the actual code of GNU gettext is covered by the GNU
# General Public License and is *not* in the public domain.
#
# Origin: gettext-0.18
GETTEXT_MACRO_VERSION = 0.18

PACKAGE = vlc
VERSION = 2.1.0-git
PACKAGE_BUGREPORT = 

SHELL = /bin/sh


srcdir = .
top_srcdir = ..


prefix = /usr/local
exec_prefix = ${prefix}
datarootdir = ${prefix}/share
datadir = ${datarootdir}
localedir = ${datarootdir}/locale
gettextsrcdir = $(datadir)/gettext/po

INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644

# We use $(mkdir_p).
# In automake <= 1.9.x, $(mkdir_p) is defined either as "mkdir -p --" or as
# "$(mkinstalldirs)" or as "$(install_sh) -d". For these automake versions,
# ${SHELL} /home/jcarrera/Documents/vlc/autotools/install-sh does not start with $(SHELL), so we add it.
# In automake >= 1.10, /bin/mkdir -p is derived from ${MKDIR_P}, which is defined
# either as "/path/to/mkdir -p" or ".../install-sh -c -d". For these automake
# versions, $(mkinstalldirs) and $(install_sh) are unused.
mkinstalldirs = $(SHELL) ${SHELL} /home/jcarrera/Documents/vlc/autotools/install-sh -d
install_sh = $(SHELL) ${SHELL} /home/jcarrera/Documents/vlc/autotools/install-sh
MKDIR_P = /bin/mkdir -p
mkdir_p = /bin/mkdir -p

GMSGFMT_ = /usr/bin/msgfmt
GMSGFMT_no = /usr/bin/msgfmt
GMSGFMT_yes = /usr/bin/msgfmt
GMSGFMT = $(GMSGFMT_$(USE_MSGCTXT))
MSGFMT_ = /usr/bin/msgfmt
MSGFMT_no = /usr/bin/msgfmt
MSGFMT_yes = /usr/bin/msgfmt
MSGFMT = $(MSGFMT_$(USE_MSGCTXT))
XGETTEXT_ = /usr/bin/xgettext
XGETTEXT_no = /usr/bin/xgettext
XGETTEXT_yes = /usr/bin/xgettext
XGETTEXT = $(XGETTEXT_$(USE_MSGCTXT))
MSGMERGE = msgmerge
MSGMERGE_UPDATE = /usr/bin/msgmerge --update
MSGINIT = msginit
MSGCONV = msgconv
MSGFILTER = msgfilter

POFILES =  ach.po af.po am.po ar.po ast.po be.po bg.po bn.po br.po ca.po cgg.po ckb.po co.po cs.po da.po de.po el.po en_GB.po es.po et.po eu.po fa.po ff.po fi.po fr.po fur.po ga.po gl.po he.po hi.po hr.po hu.po hy.po id.po is.po it.po ja.po ka.po kk.po km.po ko.po lg.po lt.po lv.po ml.po mk.po mn.po ms.po my.po nb.po ne.po nl.po nn.po oc.po pa.po pl.po ps.po pt_BR.po pt_PT.po ro.po ru.po si.po sk.po sl.po sq.po sr.po sv.po ta.po tet.po th.po tl.po tr.po uk.po vi.po wa.po zh_CN.po zh_TW.po zu.po
GMOFILES =  ach.gmo af.gmo am.gmo ar.gmo ast.gmo be.gmo bg.gmo bn.gmo br.gmo ca.gmo cgg.gmo ckb.gmo co.gmo cs.gmo da.gmo de.gmo el.gmo en_GB.gmo es.gmo et.gmo eu.gmo fa.gmo ff.gmo fi.gmo fr.gmo fur.gmo ga.gmo gl.gmo he.gmo hi.gmo hr.gmo hu.gmo hy.gmo id.gmo is.gmo it.gmo ja.gmo ka.gmo kk.gmo km.gmo ko.gmo lg.gmo lt.gmo lv.gmo ml.gmo mk.gmo mn.gmo ms.gmo my.gmo nb.gmo ne.gmo nl.gmo nn.gmo oc.gmo pa.gmo pl.gmo ps.gmo pt_BR.gmo pt_PT.gmo ro.gmo ru.gmo si.gmo sk.gmo sl.gmo sq.gmo sr.gmo sv.gmo ta.gmo tet.gmo th.gmo tl.gmo tr.gmo uk.gmo vi.gmo wa.gmo zh_CN.gmo zh_TW.gmo zu.gmo
UPDATEPOFILES =  ach.po-update af.po-update am.po-update ar.po-update ast.po-update be.po-update bg.po-update bn.po-update br.po-update ca.po-update cgg.po-update ckb.po-update co.po-update cs.po-update da.po-update de.po-update el.po-update en_GB.po-update es.po-update et.po-update eu.po-update fa.po-update ff.po-update fi.po-update fr.po-update fur.po-update ga.po-update gl.po-update he.po-update hi.po-update hr.po-update hu.po-update hy.po-update id.po-update is.po-update it.po-update ja.po-update ka.po-update kk.po-update km.po-update ko.po-update lg.po-update lt.po-update lv.po-update ml.po-update mk.po-update mn.po-update ms.po-update my.po-update nb.po-update ne.po-update nl.po-update nn.po-update oc.po-update pa.po-update pl.po-update ps.po-update pt_BR.po-update pt_PT.po-update ro.po-update ru.po-update si.po-update sk.po-update sl.po-update sq.po-update sr.po-update sv.po-update ta.po-update tet.po-update th.po-update tl.po-update tr.po-update uk.po-update vi.po-update wa.po-update zh_CN.po-update zh_TW.po-update zu.po-update
DUMMYPOFILES =  ach.nop af.nop am.nop ar.nop ast.nop be.nop bg.nop bn.nop br.nop ca.nop cgg.nop ckb.nop co.nop cs.nop da.nop de.nop el.nop en_GB.nop es.nop et.nop eu.nop fa.nop ff.nop fi.nop fr.nop fur.nop ga.nop gl.nop he.nop hi.nop hr.nop hu.nop hy.nop id.nop is.nop it.nop ja.nop ka.nop kk.nop km.nop ko.nop lg.nop lt.nop lv.nop ml.nop mk.nop mn.nop ms.nop my.nop nb.nop ne.nop nl.nop nn.nop oc.nop pa.nop pl.nop ps.nop pt_BR.nop pt_PT.nop ro.nop ru.nop si.nop sk.nop sl.nop sq.nop sr.nop sv.nop ta.nop tet.nop th.nop tl.nop tr.nop uk.nop vi.nop wa.nop zh_CN.nop zh_TW.nop zu.nop
DISTFILES.common = Makefile.in.in remove-potcdate.sin \
$(DISTFILES.common.extra1) $(DISTFILES.common.extra2) $(DISTFILES.common.extra3)
DISTFILES = $(DISTFILES.common) Makevars POTFILES.in \
$(POFILES) $(GMOFILES) \
$(DISTFILES.extra1) $(DISTFILES.extra2) $(DISTFILES.extra3)

POTFILES = \
     ../include/vlc_access.h \
     ../include/vlc_aout.h \
     ../include/vlc_arrays.h \
     ../include/vlc_bits.h \
     ../include/vlc_block.h \
     ../include/vlc_block_helper.h \
     ../include/vlc_charset.h \
     ../include/vlc_codec.h \
     ../include/vlc_codecs.h \
     ../include/vlc_codec_synchro.h \
     ../include/vlc_common.h \
     ../include/vlc_config_cat.h \
     ../include/vlc_config.h \
     ../include/vlc_configuration.h \
     ../include/vlc_demux.h \
     ../include/vlc/deprecated.h \
     ../include/vlc_epg.h \
     ../include/vlc_es.h \
     ../include/vlc_es_out.h \
     ../include/vlc_events.h \
     ../include/vlc_filter.h \
     ../include/vlc_fixups.h \
     ../include/vlc_gcrypt.h \
     ../include/vlc_httpd.h \
     ../include/vlc_image.h \
     ../include/vlc_input.h \
     ../include/vlc_interface.h \
     ../include/vlc_intf_strings.h \
     ../include/vlc_iso_lang.h \
     ../include/vlc_keys.h \
     ../include/vlc/libvlc_events.h \
     ../include/vlc/libvlc.h \
     ../include/vlc/libvlc_media_list.h \
     ../include/vlc/libvlc_structures.h \
     ../include/vlc/libvlc_vlm.h \
     ../include/vlc_main.h \
     ../include/vlc_md5.h \
     ../include/vlc_messages.h \
     ../include/vlc_meta.h \
     ../include/vlc_modules.h \
     ../include/vlc_mtime.h \
     ../include/vlc_network.h \
     ../include/vlc_objects.h \
     ../include/vlc_pgpkey.h \
     ../include/vlc_playlist.h \
     ../include/vlc_plugin.h \
     ../include/vlc_rand.h \
     ../include/vlc_services_discovery.h \
     ../include/vlc_sout.h \
     ../include/vlc_stream.h \
     ../include/vlc_strings.h \
     ../include/vlc_threads.h \
     ../include/vlc_tls.h \
     ../include/vlc_update.h \
     ../include/vlc_url.h \
     ../include/vlc_variables.h \
     ../include/vlc/vlc.h \
     ../include/vlc_vlm.h \
     ../include/vlc_vod.h \
     ../include/vlc_vout.h \
     ../include/vlc_vout_window.h \
     ../include/vlc_xml.h \
     ../src/audio_output/aout_internal.h \
     ../src/audio_output/common.c \
     ../src/audio_output/dec.c \
     ../src/audio_output/filters.c \
     ../src/audio_output/output.c \
     ../src/config/chain.c \
     ../src/config/cmdline.c \
     ../src/config/configuration.h \
     ../src/config/core.c \
     ../src/config/file.c \
     ../src/config/help.c \
     ../src/config/intf.c \
     ../src/config/keys.c \
     ../src/extras/libc.c \
     ../src/extras/tdestroy.c \
     ../src/input/access.c \
     ../src/input/access.h \
     ../src/input/clock.c \
     ../src/input/clock.h \
     ../src/input/control.c \
     ../src/input/decoder.c \
     ../src/input/decoder.h \
     ../src/input/decoder_synchro.c \
     ../src/input/demux.c \
     ../src/input/demux.h \
     ../src/input/es_out.c \
     ../src/input/es_out.h \
     ../src/input/input.c \
     ../src/input/input_internal.h \
     ../src/input/item.c \
     ../src/input/meta.c \
     ../src/input/stream.c \
     ../src/input/stream.h \
     ../src/input/stream_memory.c \
     ../src/input/subtitles.c \
     ../src/input/var.c \
     ../src/input/vlm.c \
     ../src/input/vlm_internal.h \
     ../src/input/vlmshell.c \
     ../src/interface/interface.c \
     ../src/libvlc.c \
     ../src/libvlc.h \
     ../src/libvlc-module.c \
     ../src/misc/block.c \
     ../src/misc/cpu.c \
     ../src/misc/error.c \
     ../src/misc/es_format.c \
     ../src/misc/events.c \
     ../src/misc/filter_chain.c \
     ../src/misc/image.c \
     ../src/misc/md5.c \
     ../src/misc/messages.c \
     ../src/misc/mtime.c \
     ../src/misc/objects.c \
     ../src/misc/rand.c \
     ../src/misc/threads.c \
     ../src/misc/update.c \
     ../src/misc/update.h \
     ../src/misc/variables.c \
     ../src/misc/variables.h \
     ../src/misc/xml.c \
     ../src/missing.c \
     ../src/modules/cache.c \
     ../src/modules/entry.c \
     ../src/modules/modules.c \
     ../src/modules/modules.h \
     ../src/network/getaddrinfo.c \
     ../src/network/httpd.c \
     ../src/network/io.c \
     ../src/network/rootbind.c \
     ../src/network/tcp.c \
     ../src/network/tls.c \
     ../src/network/udp.c \
     ../src/playlist/control.c \
     ../src/playlist/engine.c \
     ../src/playlist/item.c \
     ../src/playlist/loadsave.c \
     ../src/playlist/playlist_internal.h \
     ../src/playlist/search.c \
     ../src/playlist/services_discovery.c \
     ../src/playlist/sort.c \
     ../src/playlist/thread.c \
     ../src/playlist/tree.c \
     ../src/stream_output/announce.c \
     ../src/stream_output/sap.c \
     ../src/stream_output/sdp.c \
     ../src/stream_output/stream_output.c \
     ../src/stream_output/stream_output.h \
     ../src/text/iso-639_def.h \
     ../src/version.c \
     ../src/video_output/interlacing.c \
     ../src/video_output/postprocessing.c \
     ../src/video_output/video_output.c \
     ../src/video_output/video_text.c \
     ../src/video_output/video_widgets.c \
     ../src/video_output/vout_control.h \
     ../src/video_output/vout_internal.h \
     ../src/video_output/vout_intf.c \
     ../src/video_output/vout_subpictures.c \
     ../src/win32/thread.c \
     ../lib/audio.c \
     ../lib/core.c \
     ../lib/event.c \
     ../lib/libvlc_internal.h \
     ../lib/log.c \
     ../lib/media.c \
     ../lib/media_discoverer.c \
     ../lib/media_library.c \
     ../lib/media_list.c \
     ../lib/media_list_path.h \
     ../lib/media_list_player.c \
     ../lib/media_player.c \
     ../lib/playlist.c \
     ../lib/video.c \
     ../lib/vlm.c \
     ../modules/access/alsa.c \
     ../modules/access/attachment.c \
     ../modules/access/avio.h \
     ../modules/access/bd/bd.c \
     ../modules/access/bluray.c \
     ../modules/access/cdda.c \
     ../modules/access/dc1394.c \
     ../modules/access/decklink.cpp \
     ../modules/access/directory.c \
     ../modules/access/dshow/crossbar.cpp \
     ../modules/access/dshow/dshow.cpp \
     ../modules/access/dshow/filter.cpp \
     ../modules/access/dshow/filter.h \
     ../modules/access/dtv/access.c \
     ../modules/access/dv.c \
     ../modules/access/dvdnav.c \
     ../modules/access/dvdread.c \
     ../modules/access/eyetv.m \
     ../modules/access/file.c \
     ../modules/access/fs.c \
     ../modules/access/ftp.c \
     ../modules/access/gnomevfs.c \
     ../modules/access/htcpcp.c \
     ../modules/access/http.c \
     ../modules/access/idummy.c \
     ../modules/access/imem.c \
     ../modules/access/jack.c \
     ../modules/access/linsys/linsys_hdsdi.c \
     ../modules/access/linsys/linsys_sdi.c \
     ../modules/access/live555.cpp \
     ../modules/access/mms/asf.c \
     ../modules/access/mms/asf.h \
     ../modules/access/mms/buffer.c \
     ../modules/access/mms/buffer.h \
     ../modules/access/mms/mms.c \
     ../modules/access/mms/mms.h \
     ../modules/access/mms/mmsh.c \
     ../modules/access/mms/mmsh.h \
     ../modules/access/mms/mmstu.c \
     ../modules/access/mms/mmstu.h \
     ../modules/access/mtp.c \
     ../modules/access/oss.c \
     ../modules/access_output/bonjour.c \
     ../modules/access_output/bonjour.h \
     ../modules/access_output/dummy.c \
     ../modules/access_output/file.c \
     ../modules/access_output/http.c \
     ../modules/access_output/livehttp.c \
     ../modules/access_output/shout.c \
     ../modules/access_output/udp.c \
     ../modules/access/pulse.c \
     ../modules/access/qtcapture.m \
     ../modules/access/rar/access.c \
     ../modules/access/rar/rar.c \
     ../modules/access/rar/rar.h \
     ../modules/access/rar/stream.c \
     ../modules/access/rtp/input.c \
     ../modules/access/rtp/rtp.c \
     ../modules/access/rtp/rtp.h \
     ../modules/access/rtp/session.c \
     ../modules/access/rtsp/access.c \
     ../modules/access/rtsp/real_asmrp.c \
     ../modules/access/rtsp/real.c \
     ../modules/access/rtsp/real.h \
     ../modules/access/rtsp/real_rmff.c \
     ../modules/access/rtsp/real_rmff.h \
     ../modules/access/rtsp/real_sdpplin.c \
     ../modules/access/rtsp/real_sdpplin.h \
     ../modules/access/rtsp/rtsp.c \
     ../modules/access/rtsp/rtsp.h \
     ../modules/access/screen/mac.c \
     ../modules/access/screen/screen.c \
     ../modules/access/screen/screen.h \
     ../modules/access/screen/win32.c \
     ../modules/access/screen/xcb.c \
     ../modules/access/sdp.c \
     ../modules/access/sftp.c \
     ../modules/access/shm.c \
     ../modules/access/smb.c \
     ../modules/access/tcp.c \
     ../modules/access/timecode.c \
     ../modules/access/udp.c \
     ../modules/access/v4l2/controls.c \
     ../modules/access/v4l2/v4l2.c \
     ../modules/access/vcd/cdrom.c \
     ../modules/access/vcd/cdrom.h \
     ../modules/access/vcd/cdrom_internals.h \
     ../modules/access/vcd/vcd.c \
     ../modules/access/vcdx/access.c \
     ../modules/access/vcdx/info.c \
     ../modules/access/vcdx/info.h \
     ../modules/access/vcdx/vcd.c \
     ../modules/access/vcdx/vcd.h \
     ../modules/access/vcdx/vcdplayer.c \
     ../modules/access/vcdx/vcdplayer.h \
     ../modules/access/vdr.c \
     ../modules/access/zip/zipstream.c \
     ../modules/arm_neon/chroma_yuv.c \
     ../modules/arm_neon/simple_channel_mixer.c \
     ../modules/arm_neon/volume.c \
     ../modules/arm_neon/yuv_rgb.c \
     ../modules/audio_filter/audiobargraph_a.c \
     ../modules/audio_filter/channel_mixer/dolby.c \
     ../modules/audio_filter/channel_mixer/headphone.c \
     ../modules/audio_filter/channel_mixer/mono.c \
     ../modules/audio_filter/channel_mixer/remap.c \
     ../modules/audio_filter/channel_mixer/simple.c \
     ../modules/audio_filter/channel_mixer/trivial.c \
     ../modules/audio_filter/chorus_flanger.c \
     ../modules/audio_filter/compressor.c \
     ../modules/audio_filter/converter/a52tofloat32.c \
     ../modules/audio_filter/converter/a52tospdif.c \
     ../modules/audio_filter/converter/dtstofloat32.c \
     ../modules/audio_filter/converter/dtstospdif.c \
     ../modules/audio_filter/converter/format.c \
     ../modules/audio_filter/converter/mpgatofixed32.c \
     ../modules/audio_filter/equalizer.c \
     ../modules/audio_filter/equalizer_presets.h \
     ../modules/audio_filter/gain.c \
     ../modules/audio_filter/karaoke.c \
     ../modules/audio_filter/normvol.c \
     ../modules/audio_filter/param_eq.c \
     ../modules/audio_filter/resampler/bandlimited.c \
     ../modules/audio_filter/resampler/bandlimited.h \
     ../modules/audio_filter/resampler/speex.c \
     ../modules/audio_filter/resampler/src.c \
     ../modules/audio_filter/resampler/ugly.c \
     ../modules/audio_filter/scaletempo.c \
     ../modules/audio_filter/spatializer/allpass.cpp \
     ../modules/audio_filter/spatializer/allpass.hpp \
     ../modules/audio_filter/spatializer/comb.cpp \
     ../modules/audio_filter/spatializer/comb.hpp \
     ../modules/audio_filter/spatializer/denormals.h \
     ../modules/audio_filter/spatializer/revmodel.cpp \
     ../modules/audio_filter/spatializer/revmodel.hpp \
     ../modules/audio_filter/spatializer/spatializer.cpp \
     ../modules/audio_filter/spatializer/tuning.h \
     ../modules/audio_filter/stereo_widen.c \
     ../modules/audio_mixer/float.c \
     ../modules/audio_mixer/integer.c \
     ../modules/audio_output/adummy.c \
     ../modules/audio_output/alsa.c \
     ../modules/audio_output/amem.c \
     ../modules/audio_output/audioqueue.c \
     ../modules/audio_output/audiotrack.c \
     ../modules/audio_output/auhal.c \
     ../modules/audio_output/directx.c \
     ../modules/audio_output/file.c \
     ../modules/audio_output/jack.c \
     ../modules/audio_output/kai.c \
     ../modules/audio_output/opensles_android.c \
     ../modules/audio_output/oss.c \
     ../modules/audio_output/pulse.c \
     ../modules/audio_output/sndio.c \
     ../modules/audio_output/volume.h \
     ../modules/audio_output/wasapi.c \
     ../modules/audio_output/waveout.c \
     ../modules/audio_output/windows_audio_common.h \
     ../modules/codec/a52.c \
     ../modules/codec/adpcm.c \
     ../modules/codec/aes3.c \
     ../modules/codec/araw.c \
     ../modules/codec/avcodec/audio.c \
     ../modules/codec/avcodec/avcodec.c \
     ../modules/codec/avcodec/avcodec.h \
     ../modules/codec/avcodec/chroma.c \
     ../modules/codec/avcodec/deinterlace.c \
     ../modules/codec/avcodec/dxva2.c \
     ../modules/codec/avcodec/encoder.c \
     ../modules/codec/avcodec/fourcc.c \
     ../modules/codec/avcodec/vaapi.c \
     ../modules/codec/avcodec/vda.c \
     ../modules/codec/avcodec/vdpau.c \
     ../modules/codec/avcodec/video.c \
     ../modules/codec/cc.c \
     ../modules/codec/cc.h \
     ../modules/codec/cdg.c \
     ../modules/codec/crystalhd.c \
     ../modules/codec/cvdsub.c \
     ../modules/codec/ddummy.c \
     ../modules/codec/dirac.c \
     ../modules/codec/dmo/buffer.c \
     ../modules/codec/dmo/dmo.c \
     ../modules/codec/dmo/dmo.h \
     ../modules/codec/dts.c \
     ../modules/codec/dvbsub.c \
     ../modules/codec/edummy.c \
     ../modules/codec/faad.c \
     ../modules/codec/fdkaac.c \
     ../modules/codec/flac.c \
     ../modules/codec/fluidsynth.c \
     ../modules/codec/g711.c \
     ../modules/codec/kate.c \
     ../modules/codec/libass.c \
     ../modules/codec/libmpeg2.c \
     ../modules/codec/lpcm.c \
     ../modules/codec/mash.cpp \
     ../modules/codec/mpeg_audio.c \
     ../modules/codec/omxil/android_mediacodec.c \
     ../modules/codec/omxil/omxil.c \
     ../modules/codec/omxil/omxil.h \
     ../modules/codec/omxil/omxil_utils.h \
     ../modules/codec/omxil/utils.c \
     ../modules/codec/opus.c \
     ../modules/codec/png.c \
     ../modules/codec/quicktime.c \
     ../modules/codec/rawvideo.c \
     ../modules/codec/schroedinger.c \
     ../modules/codec/sdl_image.c \
     ../modules/codec/shine/shine_mod.c \
     ../modules/codec/speex.c \
     ../modules/codec/spudec/parse.c \
     ../modules/codec/spudec/spudec.c \
     ../modules/codec/spudec/spudec.h \
     ../modules/codec/stl.c \
     ../modules/codec/subsdec.c \
     ../modules/codec/subsusf.c \
     ../modules/codec/svcdsub.c \
     ../modules/codec/t140.c \
     ../modules/codec/telx.c \
     ../modules/codec/theora.c \
     ../modules/codec/twolame.c \
     ../modules/codec/uleaddvaudio.c \
     ../modules/codec/vorbis.c \
     ../modules/codec/wmafixed/wma.c \
     ../modules/codec/x264.c \
     ../modules/codec/xwd.c \
     ../modules/codec/zvbi.c \
     ../modules/control/dbus/dbus.c \
     ../modules/control/dbus/dbus_common.h \
     ../modules/control/dbus/dbus_player.c \
     ../modules/control/dbus/dbus_player.h \
     ../modules/control/dbus/dbus_root.c \
     ../modules/control/dbus/dbus_root.h \
     ../modules/control/dbus/dbus_tracklist.c \
     ../modules/control/dbus/dbus_tracklist.h \
     ../modules/control/dummy.c \
     ../modules/control/gestures.c \
     ../modules/control/globalhotkeys/win32.c \
     ../modules/control/globalhotkeys/xcb.c \
     ../modules/control/hotkeys.c \
     ../modules/control/lirc.c \
     ../modules/control/motion.c \
     ../modules/control/netsync.c \
     ../modules/control/ntservice.c \
     ../modules/control/rc.c \
     ../modules/control/unimotion.c \
     ../modules/control/unimotion.h \
     ../modules/demux/aiff.c \
     ../modules/demux/asf/asf.c \
     ../modules/demux/asf/libasf.c \
     ../modules/demux/asf/libasf.h \
     ../modules/demux/au.c \
     ../modules/demux/avformat/avformat.c \
     ../modules/demux/avformat/avformat.h \
     ../modules/demux/avformat/demux.c \
     ../modules/demux/avformat/mux.c \
     ../modules/demux/avi/avi.c \
     ../modules/demux/avi/libavi.c \
     ../modules/demux/avi/libavi.h \
     ../modules/demux/cdg.c \
     ../modules/demux/demuxdump.c \
     ../modules/demux/dirac.c \
     ../modules/demux/flac.c \
     ../modules/demux/gme.c \
     ../modules/demux/image.c \
     ../modules/demux/kate_categories.c \
     ../modules/demux/mjpeg.c \
     ../modules/demux/mkv/chapter_command.cpp \
     ../modules/demux/mkv/chapter_command.hpp \
     ../modules/demux/mkv/chapters.cpp \
     ../modules/demux/mkv/chapters.hpp \
     ../modules/demux/mkv/demux.cpp \
     ../modules/demux/mkv/demux.hpp \
     ../modules/demux/mkv/Ebml_parser.cpp \
     ../modules/demux/mkv/Ebml_parser.hpp \
     ../modules/demux/mkv/matroska_segment.cpp \
     ../modules/demux/mkv/matroska_segment.hpp \
     ../modules/demux/mkv/matroska_segment_parse.cpp \
     ../modules/demux/mkv/mkv.cpp \
     ../modules/demux/mkv/mkv.hpp \
     ../modules/demux/mkv/stream_io_callback.cpp \
     ../modules/demux/mkv/stream_io_callback.hpp \
     ../modules/demux/mkv/util.cpp \
     ../modules/demux/mkv/util.hpp \
     ../modules/demux/mkv/virtual_segment.cpp \
     ../modules/demux/mkv/virtual_segment.hpp \
     ../modules/demux/mod.c \
     ../modules/demux/mp4/id3genres.h \
     ../modules/demux/mp4/libmp4.c \
     ../modules/demux/mp4/libmp4.h \
     ../modules/demux/mp4/mp4.c \
     ../modules/demux/mpc.c \
     ../modules/demux/mpeg/es.c \
     ../modules/demux/mpeg/h264.c \
     ../modules/demux/mpeg/mpgv.c \
     ../modules/demux/nsc.c \
     ../modules/demux/nsv.c \
     ../modules/demux/nuv.c \
     ../modules/demux/ogg.c \
     ../modules/demux/playlist/asx.c \
     ../modules/demux/playlist/b4s.c \
     ../modules/demux/playlist/dvb.c \
     ../modules/demux/playlist/gvp.c \
     ../modules/demux/playlist/ifo.c \
     ../modules/demux/playlist/itml.c \
     ../modules/demux/playlist/itml.h \
     ../modules/demux/playlist/m3u.c \
     ../modules/demux/playlist/playlist.c \
     ../modules/demux/playlist/playlist.h \
     ../modules/demux/playlist/pls.c \
     ../modules/demux/playlist/podcast.c \
     ../modules/demux/playlist/qtl.c \
     ../modules/demux/playlist/sgimb.c \
     ../modules/demux/playlist/shoutcast.c \
     ../modules/demux/playlist/xspf.c \
     ../modules/demux/ps.c \
     ../modules/demux/ps.h \
     ../modules/demux/pva.c \
     ../modules/demux/rawaud.c \
     ../modules/demux/rawdv.c \
     ../modules/demux/rawvid.c \
     ../modules/demux/real.c \
     ../modules/demux/sid.cpp \
     ../modules/demux/smf.c \
     ../modules/demux/stl.c \
     ../modules/demux/subtitle.c \
     ../modules/demux/ts.c \
     ../modules/demux/tta.c \
     ../modules/demux/ty.c \
     ../modules/demux/vc1.c \
     ../modules/demux/vobsub.c \
     ../modules/demux/voc.c \
     ../modules/demux/wav.c \
     ../modules/demux/xa.c \
     ../modules/gui/macosx/about.h \
     ../modules/gui/macosx/about.m \
     ../modules/gui/macosx/AppleRemote.h \
     ../modules/gui/macosx/AppleRemote.m \
     ../modules/gui/macosx/applescript.h \
     ../modules/gui/macosx/applescript.m \
     ../modules/gui/macosx/AudioEffects.h \
     ../modules/gui/macosx/AudioEffects.m \
     ../modules/gui/macosx/bookmarks.h \
     ../modules/gui/macosx/bookmarks.m \
     ../modules/gui/macosx/controls.h \
     ../modules/gui/macosx/controls.m \
     ../modules/gui/macosx/ControlsBar.h \
     ../modules/gui/macosx/ControlsBar.m \
     ../modules/gui/macosx/ConvertAndSave.h \
     ../modules/gui/macosx/ConvertAndSave.m \
     ../modules/gui/macosx/coredialogs.h \
     ../modules/gui/macosx/coredialogs.m \
     ../modules/gui/macosx/CoreInteraction.h \
     ../modules/gui/macosx/CoreInteraction.m \
     ../modules/gui/macosx_dialog_provider/dialogProvider.m \
     ../modules/gui/macosx_dialog_provider/VLCLoginPanel.h \
     ../modules/gui/macosx_dialog_provider/VLCLoginPanel.m \
     ../modules/gui/macosx_dialog_provider/VLCProgressPanel.h \
     ../modules/gui/macosx_dialog_provider/VLCProgressPanel.m \
     ../modules/gui/macosx/ExtensionsDialogProvider.h \
     ../modules/gui/macosx/ExtensionsDialogProvider.m \
     ../modules/gui/macosx/ExtensionsManager.h \
     ../modules/gui/macosx/ExtensionsManager.m \
     ../modules/gui/macosx/eyetv.h \
     ../modules/gui/macosx/eyetv.m \
     ../modules/gui/macosx/fspanel.h \
     ../modules/gui/macosx/fspanel.m \
     ../modules/gui/macosx/intf.h \
     ../modules/gui/macosx/intf.m \
     ../modules/gui/macosx/macosx.m \
     ../modules/gui/macosx/MainMenu.h \
     ../modules/gui/macosx/MainMenu.m \
     ../modules/gui/macosx/MainWindow.h \
     ../modules/gui/macosx/MainWindow.m \
     ../modules/gui/macosx/MainWindowTitle.h \
     ../modules/gui/macosx/MainWindowTitle.m \
     ../modules/gui/macosx/misc.h \
     ../modules/gui/macosx/misc.m \
     ../modules/gui/macosx/open.h \
     ../modules/gui/macosx/open.m \
     ../modules/gui/macosx/output.h \
     ../modules/gui/macosx/output.m \
     ../modules/gui/macosx/playlist.h \
     ../modules/gui/macosx/playlist.m \
     ../modules/gui/macosx/playlistinfo.h \
     ../modules/gui/macosx/playlistinfo.m \
     ../modules/gui/macosx/prefs.h \
     ../modules/gui/macosx/prefs.m \
     ../modules/gui/macosx/prefs_widgets.h \
     ../modules/gui/macosx/prefs_widgets.m \
     ../modules/gui/macosx/simple_prefs.h \
     ../modules/gui/macosx/simple_prefs.m \
     ../modules/gui/macosx/StringUtility.h \
     ../modules/gui/macosx/StringUtility.m \
     ../modules/gui/macosx/TrackSynchronization.h \
     ../modules/gui/macosx/TrackSynchronization.m \
     ../modules/gui/macosx/VideoEffects.h \
     ../modules/gui/macosx/VideoEffects.m \
     ../modules/gui/macosx/VideoView.h \
     ../modules/gui/macosx/VideoView.m \
     ../modules/gui/macosx/VLCVoutWindowController.h \
     ../modules/gui/macosx/VLCVoutWindowController.m \
     ../modules/gui/macosx/Windows.h \
     ../modules/gui/macosx/Windows.m \
     ../modules/gui/macosx/wizard.h \
     ../modules/gui/macosx/wizard.m \
     ../modules/gui/minimal_macosx/intf.h \
     ../modules/gui/minimal_macosx/intf.m \
     ../modules/gui/minimal_macosx/macosx.c \
     ../modules/gui/minimal_macosx/VLCMinimalVoutWindow.h \
     ../modules/gui/minimal_macosx/VLCMinimalVoutWindow.m \
     ../modules/gui/minimal_macosx/misc.h \
     ../modules/gui/minimal_macosx/misc.m \
     ../modules/gui/ncurses.c \
     ../modules/gui/qt4/components/complete_preferences.cpp \
     ../modules/gui/qt4/components/complete_preferences.hpp \
     ../modules/gui/qt4/components/controller.cpp \
     ../modules/gui/qt4/components/controller.hpp \
     ../modules/gui/qt4/components/controller_widget.cpp \
     ../modules/gui/qt4/components/controller_widget.hpp \
     ../modules/gui/qt4/components/extended_panels.cpp \
     ../modules/gui/qt4/components/extended_panels.hpp \
     ../modules/gui/qt4/components/info_panels.cpp \
     ../modules/gui/qt4/components/info_panels.hpp \
     ../modules/gui/qt4/components/interface_widgets.cpp \
     ../modules/gui/qt4/components/interface_widgets.hpp \
     ../modules/gui/qt4/components/open_panels.cpp \
     ../modules/gui/qt4/components/open_panels.hpp \
     ../modules/gui/qt4/components/playlist/playlist.cpp \
     ../modules/gui/qt4/components/playlist/playlist.hpp \
     ../modules/gui/qt4/components/playlist/playlist_item.cpp \
     ../modules/gui/qt4/components/playlist/playlist_item.hpp \
     ../modules/gui/qt4/components/playlist/playlist_model.cpp \
     ../modules/gui/qt4/components/playlist/playlist_model.hpp \
     ../modules/gui/qt4/components/playlist/selector.cpp \
     ../modules/gui/qt4/components/playlist/selector.hpp \
     ../modules/gui/qt4/components/playlist/sorting.h \
     ../modules/gui/qt4/components/playlist/standardpanel.cpp \
     ../modules/gui/qt4/components/playlist/standardpanel.hpp \
     ../modules/gui/qt4/components/preferences_widgets.cpp \
     ../modules/gui/qt4/components/preferences_widgets.hpp \
     ../modules/gui/qt4/components/simple_preferences.cpp \
     ../modules/gui/qt4/components/simple_preferences.hpp \
     ../modules/gui/qt4/components/sout/profile_selector.cpp \
     ../modules/gui/qt4/components/sout/sout_widgets.cpp \
     ../modules/gui/qt4/dialogs/bookmarks.cpp \
     ../modules/gui/qt4/dialogs/bookmarks.hpp \
     ../modules/gui/qt4/dialogs/convert.cpp \
     ../modules/gui/qt4/dialogs/convert.hpp \
     ../modules/gui/qt4/dialogs/errors.cpp \
     ../modules/gui/qt4/dialogs/errors.hpp \
     ../modules/gui/qt4/dialogs/extended.cpp \
     ../modules/gui/qt4/dialogs/extended.hpp \
     ../modules/gui/qt4/dialogs/external.cpp \
     ../modules/gui/qt4/dialogs/external.hpp \
     ../modules/gui/qt4/dialogs/firstrun.cpp \
     ../modules/gui/qt4/dialogs/gototime.cpp \
     ../modules/gui/qt4/dialogs/gototime.hpp \
     ../modules/gui/qt4/dialogs/help.cpp \
     ../modules/gui/qt4/dialogs/help.hpp \
     ../modules/gui/qt4/dialogs/mediainfo.cpp \
     ../modules/gui/qt4/dialogs/mediainfo.hpp \
     ../modules/gui/qt4/dialogs/messages.cpp \
     ../modules/gui/qt4/dialogs/messages.hpp \
     ../modules/gui/qt4/dialogs/open.cpp \
     ../modules/gui/qt4/dialogs/open.hpp \
     ../modules/gui/qt4/dialogs/openurl.cpp \
     ../modules/gui/qt4/dialogs/openurl.hpp \
     ../modules/gui/qt4/dialogs/playlist.cpp \
     ../modules/gui/qt4/dialogs/playlist.hpp \
     ../modules/gui/qt4/dialogs/plugins.cpp \
     ../modules/gui/qt4/dialogs/podcast_configuration.cpp \
     ../modules/gui/qt4/dialogs/podcast_configuration.hpp \
     ../modules/gui/qt4/dialogs/preferences.cpp \
     ../modules/gui/qt4/dialogs/preferences.hpp \
     ../modules/gui/qt4/dialogs_provider.cpp \
     ../modules/gui/qt4/dialogs_provider.hpp \
     ../modules/gui/qt4/dialogs/sout.cpp \
     ../modules/gui/qt4/dialogs/sout.hpp \
     ../modules/gui/qt4/dialogs/toolbar.cpp \
     ../modules/gui/qt4/dialogs/toolbar.hpp \
     ../modules/gui/qt4/dialogs/vlm.cpp \
     ../modules/gui/qt4/dialogs/vlm.hpp \
     ../modules/gui/qt4/input_manager.cpp \
     ../modules/gui/qt4/input_manager.hpp \
     ../modules/gui/qt4/main_interface.cpp \
     ../modules/gui/qt4/main_interface.hpp \
     ../modules/gui/qt4/menus.cpp \
     ../modules/gui/qt4/menus.hpp \
     ../modules/gui/qt4/qt4.cpp \
     ../modules/gui/qt4/qt4.hpp \
     ../modules/gui/qt4/recents.cpp \
     ../modules/gui/qt4/recents.hpp \
     ../modules/gui/qt4/util/customwidgets.cpp \
     ../modules/gui/qt4/util/customwidgets.hpp \
     ../modules/gui/qt4/util/input_slider.cpp \
     ../modules/gui/qt4/util/input_slider.hpp \
     ../modules/gui/qt4/util/qvlcapp.hpp \
     ../modules/gui/qt4/util/qvlcframe.hpp \
     ../modules/gui/qt4/util/registry.cpp \
     ../modules/gui/qt4/util/registry.hpp \
     ../modules/gui/skins2/commands/async_queue.cpp \
     ../modules/gui/skins2/commands/async_queue.hpp \
     ../modules/gui/skins2/commands/cmd_add_item.cpp \
     ../modules/gui/skins2/commands/cmd_add_item.hpp \
     ../modules/gui/skins2/commands/cmd_audio.cpp \
     ../modules/gui/skins2/commands/cmd_audio.hpp \
     ../modules/gui/skins2/commands/cmd_change_skin.cpp \
     ../modules/gui/skins2/commands/cmd_change_skin.hpp \
     ../modules/gui/skins2/commands/cmd_dialogs.hpp \
     ../modules/gui/skins2/commands/cmd_dummy.hpp \
     ../modules/gui/skins2/commands/cmd_dvd.cpp \
     ../modules/gui/skins2/commands/cmd_dvd.hpp \
     ../modules/gui/skins2/commands/cmd_fullscreen.cpp \
     ../modules/gui/skins2/commands/cmd_fullscreen.hpp \
     ../modules/gui/skins2/commands/cmd_generic.hpp \
     ../modules/gui/skins2/commands/cmd_input.cpp \
     ../modules/gui/skins2/commands/cmd_input.hpp \
     ../modules/gui/skins2/commands/cmd_layout.cpp \
     ../modules/gui/skins2/commands/cmd_layout.hpp \
     ../modules/gui/skins2/commands/cmd_minimize.cpp \
     ../modules/gui/skins2/commands/cmd_minimize.hpp \
     ../modules/gui/skins2/commands/cmd_muxer.cpp \
     ../modules/gui/skins2/commands/cmd_muxer.hpp \
     ../modules/gui/skins2/commands/cmd_on_top.cpp \
     ../modules/gui/skins2/commands/cmd_on_top.hpp \
     ../modules/gui/skins2/commands/cmd_playlist.cpp \
     ../modules/gui/skins2/commands/cmd_playlist.hpp \
     ../modules/gui/skins2/commands/cmd_playtree.cpp \
     ../modules/gui/skins2/commands/cmd_playtree.hpp \
     ../modules/gui/skins2/commands/cmd_quit.cpp \
     ../modules/gui/skins2/commands/cmd_quit.hpp \
     ../modules/gui/skins2/commands/cmd_resize.cpp \
     ../modules/gui/skins2/commands/cmd_resize.hpp \
     ../modules/gui/skins2/commands/cmd_show_window.hpp \
     ../modules/gui/skins2/commands/cmd_snapshot.cpp \
     ../modules/gui/skins2/commands/cmd_snapshot.hpp \
     ../modules/gui/skins2/commands/cmd_vars.cpp \
     ../modules/gui/skins2/commands/cmd_vars.hpp \
     ../modules/gui/skins2/controls/ctrl_button.cpp \
     ../modules/gui/skins2/controls/ctrl_button.hpp \
     ../modules/gui/skins2/controls/ctrl_checkbox.cpp \
     ../modules/gui/skins2/controls/ctrl_checkbox.hpp \
     ../modules/gui/skins2/controls/ctrl_flat.hpp \
     ../modules/gui/skins2/controls/ctrl_generic.cpp \
     ../modules/gui/skins2/controls/ctrl_generic.hpp \
     ../modules/gui/skins2/controls/ctrl_image.cpp \
     ../modules/gui/skins2/controls/ctrl_image.hpp \
     ../modules/gui/skins2/controls/ctrl_list.cpp \
     ../modules/gui/skins2/controls/ctrl_list.hpp \
     ../modules/gui/skins2/controls/ctrl_move.cpp \
     ../modules/gui/skins2/controls/ctrl_move.hpp \
     ../modules/gui/skins2/controls/ctrl_radialslider.cpp \
     ../modules/gui/skins2/controls/ctrl_radialslider.hpp \
     ../modules/gui/skins2/controls/ctrl_resize.cpp \
     ../modules/gui/skins2/controls/ctrl_resize.hpp \
     ../modules/gui/skins2/controls/ctrl_slider.cpp \
     ../modules/gui/skins2/controls/ctrl_slider.hpp \
     ../modules/gui/skins2/controls/ctrl_text.cpp \
     ../modules/gui/skins2/controls/ctrl_text.hpp \
     ../modules/gui/skins2/controls/ctrl_tree.cpp \
     ../modules/gui/skins2/controls/ctrl_tree.hpp \
     ../modules/gui/skins2/controls/ctrl_video.cpp \
     ../modules/gui/skins2/controls/ctrl_video.hpp \
     ../modules/gui/skins2/events/evt_enter.hpp \
     ../modules/gui/skins2/events/evt_focus.hpp \
     ../modules/gui/skins2/events/evt_generic.hpp \
     ../modules/gui/skins2/events/evt_input.cpp \
     ../modules/gui/skins2/events/evt_input.hpp \
     ../modules/gui/skins2/events/evt_key.cpp \
     ../modules/gui/skins2/events/evt_key.hpp \
     ../modules/gui/skins2/events/evt_leave.hpp \
     ../modules/gui/skins2/events/evt_menu.hpp \
     ../modules/gui/skins2/events/evt_motion.hpp \
     ../modules/gui/skins2/events/evt_mouse.cpp \
     ../modules/gui/skins2/events/evt_mouse.hpp \
     ../modules/gui/skins2/events/evt_refresh.hpp \
     ../modules/gui/skins2/events/evt_scroll.cpp \
     ../modules/gui/skins2/events/evt_scroll.hpp \
     ../modules/gui/skins2/events/evt_special.cpp \
     ../modules/gui/skins2/events/evt_special.hpp \
     ../modules/gui/skins2/macosx/macosx_dragdrop.cpp \
     ../modules/gui/skins2/macosx/macosx_dragdrop.hpp \
     ../modules/gui/skins2/macosx/macosx_factory.cpp \
     ../modules/gui/skins2/macosx/macosx_factory.hpp \
     ../modules/gui/skins2/macosx/macosx_graphics.cpp \
     ../modules/gui/skins2/macosx/macosx_graphics.hpp \
     ../modules/gui/skins2/macosx/macosx_loop.cpp \
     ../modules/gui/skins2/macosx/macosx_loop.hpp \
     ../modules/gui/skins2/macosx/macosx_popup.cpp \
     ../modules/gui/skins2/macosx/macosx_popup.hpp \
     ../modules/gui/skins2/macosx/macosx_timer.cpp \
     ../modules/gui/skins2/macosx/macosx_timer.hpp \
     ../modules/gui/skins2/macosx/macosx_tooltip.cpp \
     ../modules/gui/skins2/macosx/macosx_tooltip.hpp \
     ../modules/gui/skins2/macosx/macosx_window.cpp \
     ../modules/gui/skins2/macosx/macosx_window.hpp \
     ../modules/gui/skins2/parser/builder.cpp \
     ../modules/gui/skins2/parser/builder_data.hpp \
     ../modules/gui/skins2/parser/builder.hpp \
     ../modules/gui/skins2/parser/expr_evaluator.cpp \
     ../modules/gui/skins2/parser/expr_evaluator.hpp \
     ../modules/gui/skins2/parser/interpreter.cpp \
     ../modules/gui/skins2/parser/interpreter.hpp \
     ../modules/gui/skins2/parser/skin_parser.cpp \
     ../modules/gui/skins2/parser/skin_parser.hpp \
     ../modules/gui/skins2/parser/xmlparser.cpp \
     ../modules/gui/skins2/parser/xmlparser.hpp \
     ../modules/gui/skins2/src/anchor.cpp \
     ../modules/gui/skins2/src/anchor.hpp \
     ../modules/gui/skins2/src/anim_bitmap.cpp \
     ../modules/gui/skins2/src/anim_bitmap.hpp \
     ../modules/gui/skins2/src/bitmap_font.cpp \
     ../modules/gui/skins2/src/bitmap_font.hpp \
     ../modules/gui/skins2/src/dialogs.cpp \
     ../modules/gui/skins2/src/dialogs.hpp \
     ../modules/gui/skins2/src/file_bitmap.cpp \
     ../modules/gui/skins2/src/file_bitmap.hpp \
     ../modules/gui/skins2/src/ft2_bitmap.cpp \
     ../modules/gui/skins2/src/ft2_bitmap.hpp \
     ../modules/gui/skins2/src/ft2_font.cpp \
     ../modules/gui/skins2/src/ft2_font.hpp \
     ../modules/gui/skins2/src/generic_bitmap.cpp \
     ../modules/gui/skins2/src/generic_bitmap.hpp \
     ../modules/gui/skins2/src/generic_font.hpp \
     ../modules/gui/skins2/src/generic_layout.cpp \
     ../modules/gui/skins2/src/generic_layout.hpp \
     ../modules/gui/skins2/src/generic_window.cpp \
     ../modules/gui/skins2/src/generic_window.hpp \
     ../modules/gui/skins2/src/ini_file.cpp \
     ../modules/gui/skins2/src/ini_file.hpp \
     ../modules/gui/skins2/src/logger.cpp \
     ../modules/gui/skins2/src/logger.hpp \
     ../modules/gui/skins2/src/os_factory.cpp \
     ../modules/gui/skins2/src/os_factory.hpp \
     ../modules/gui/skins2/src/os_graphics.hpp \
     ../modules/gui/skins2/src/os_loop.hpp \
     ../modules/gui/skins2/src/os_popup.hpp \
     ../modules/gui/skins2/src/os_timer.hpp \
     ../modules/gui/skins2/src/os_tooltip.hpp \
     ../modules/gui/skins2/src/os_window.hpp \
     ../modules/gui/skins2/src/popup.cpp \
     ../modules/gui/skins2/src/popup.hpp \
     ../modules/gui/skins2/src/scaled_bitmap.cpp \
     ../modules/gui/skins2/src/scaled_bitmap.hpp \
     ../modules/gui/skins2/src/skin_common.hpp \
     ../modules/gui/skins2/src/skin_main.cpp \
     ../modules/gui/skins2/src/theme.cpp \
     ../modules/gui/skins2/src/theme.hpp \
     ../modules/gui/skins2/src/theme_loader.cpp \
     ../modules/gui/skins2/src/theme_loader.hpp \
     ../modules/gui/skins2/src/theme_repository.cpp \
     ../modules/gui/skins2/src/theme_repository.hpp \
     ../modules/gui/skins2/src/tooltip.cpp \
     ../modules/gui/skins2/src/tooltip.hpp \
     ../modules/gui/skins2/src/top_window.cpp \
     ../modules/gui/skins2/src/top_window.hpp \
     ../modules/gui/skins2/src/var_manager.cpp \
     ../modules/gui/skins2/src/var_manager.hpp \
     ../modules/gui/skins2/src/vlcproc.cpp \
     ../modules/gui/skins2/src/vlcproc.hpp \
     ../modules/gui/skins2/src/vout_window.cpp \
     ../modules/gui/skins2/src/vout_window.hpp \
     ../modules/gui/skins2/src/window_manager.cpp \
     ../modules/gui/skins2/src/window_manager.hpp \
     ../modules/gui/skins2/utils/bezier.cpp \
     ../modules/gui/skins2/utils/bezier.hpp \
     ../modules/gui/skins2/utils/fsm.cpp \
     ../modules/gui/skins2/utils/fsm.hpp \
     ../modules/gui/skins2/utils/observer.hpp \
     ../modules/gui/skins2/utils/pointer.hpp \
     ../modules/gui/skins2/utils/position.cpp \
     ../modules/gui/skins2/utils/position.hpp \
     ../modules/gui/skins2/utils/ustring.cpp \
     ../modules/gui/skins2/utils/ustring.hpp \
     ../modules/gui/skins2/utils/var_bool.cpp \
     ../modules/gui/skins2/utils/var_bool.hpp \
     ../modules/gui/skins2/utils/variable.hpp \
     ../modules/gui/skins2/utils/var_list.cpp \
     ../modules/gui/skins2/utils/var_list.hpp \
     ../modules/gui/skins2/utils/var_percent.cpp \
     ../modules/gui/skins2/utils/var_percent.hpp \
     ../modules/gui/skins2/utils/var_text.cpp \
     ../modules/gui/skins2/utils/var_text.hpp \
     ../modules/gui/skins2/utils/var_tree.cpp \
     ../modules/gui/skins2/utils/var_tree.hpp \
     ../modules/gui/skins2/vars/equalizer.cpp \
     ../modules/gui/skins2/vars/equalizer.hpp \
     ../modules/gui/skins2/vars/playtree.cpp \
     ../modules/gui/skins2/vars/playtree.hpp \
     ../modules/gui/skins2/vars/time.cpp \
     ../modules/gui/skins2/vars/time.hpp \
     ../modules/gui/skins2/vars/volume.cpp \
     ../modules/gui/skins2/vars/volume.hpp \
     ../modules/gui/skins2/win32/win32_dragdrop.cpp \
     ../modules/gui/skins2/win32/win32_dragdrop.hpp \
     ../modules/gui/skins2/win32/win32_factory.cpp \
     ../modules/gui/skins2/win32/win32_factory.hpp \
     ../modules/gui/skins2/win32/win32_graphics.cpp \
     ../modules/gui/skins2/win32/win32_graphics.hpp \
     ../modules/gui/skins2/win32/win32_loop.cpp \
     ../modules/gui/skins2/win32/win32_loop.hpp \
     ../modules/gui/skins2/win32/win32_popup.cpp \
     ../modules/gui/skins2/win32/win32_popup.hpp \
     ../modules/gui/skins2/win32/win32_timer.cpp \
     ../modules/gui/skins2/win32/win32_timer.hpp \
     ../modules/gui/skins2/win32/win32_tooltip.cpp \
     ../modules/gui/skins2/win32/win32_tooltip.hpp \
     ../modules/gui/skins2/win32/win32_window.cpp \
     ../modules/gui/skins2/win32/win32_window.hpp \
     ../modules/gui/skins2/x11/x11_display.cpp \
     ../modules/gui/skins2/x11/x11_display.hpp \
     ../modules/gui/skins2/x11/x11_dragdrop.cpp \
     ../modules/gui/skins2/x11/x11_dragdrop.hpp \
     ../modules/gui/skins2/x11/x11_factory.cpp \
     ../modules/gui/skins2/x11/x11_factory.hpp \
     ../modules/gui/skins2/x11/x11_graphics.cpp \
     ../modules/gui/skins2/x11/x11_graphics.hpp \
     ../modules/gui/skins2/x11/x11_loop.cpp \
     ../modules/gui/skins2/x11/x11_loop.hpp \
     ../modules/gui/skins2/x11/x11_popup.cpp \
     ../modules/gui/skins2/x11/x11_popup.hpp \
     ../modules/gui/skins2/x11/x11_timer.cpp \
     ../modules/gui/skins2/x11/x11_timer.hpp \
     ../modules/gui/skins2/x11/x11_tooltip.cpp \
     ../modules/gui/skins2/x11/x11_tooltip.hpp \
     ../modules/gui/skins2/x11/x11_window.cpp \
     ../modules/gui/skins2/x11/x11_window.hpp \
     ../modules/lua/demux.c \
     ../modules/lua/intf.c \
     ../modules/lua/libs/configuration.c \
     ../modules/lua/libs.h \
     ../modules/lua/libs/httpd.c \
     ../modules/lua/libs/input.c \
     ../modules/lua/libs/input.h \
     ../modules/lua/libs/messages.c \
     ../modules/lua/libs/misc.c \
     ../modules/lua/libs/misc.h \
     ../modules/lua/libs/net.c \
     ../modules/lua/libs/objects.c \
     ../modules/lua/libs/objects.h \
     ../modules/lua/libs/osd.c \
     ../modules/lua/libs/playlist.c \
     ../modules/lua/libs/playlist.h \
     ../modules/lua/libs/sd.c \
     ../modules/lua/libs/stream.c \
     ../modules/lua/libs/strings.c \
     ../modules/lua/libs/variables.c \
     ../modules/lua/libs/variables.h \
     ../modules/lua/libs/video.c \
     ../modules/lua/libs/vlm.c \
     ../modules/lua/libs/volume.c \
     ../modules/lua/meta.c \
     ../modules/lua/vlc.c \
     ../modules/lua/vlc.h \
     ../modules/media_library/sql_media_library.c \
     ../modules/meta_engine/folder.c \
     ../modules/meta_engine/taglib.cpp \
     ../modules/misc/audioscrobbler.c \
     ../modules/misc/dhparams.h \
     ../modules/misc/gnutls.c \
     ../modules/misc/inhibit/dbus.c \
     ../modules/misc/inhibit/xdg.c \
     ../modules/misc/logger.c \
     ../modules/misc/playlist/export.c \
     ../modules/misc/playlist/html.c \
     ../modules/misc/playlist/m3u.c \
     ../modules/misc/playlist/xspf.c \
     ../modules/misc/rtsp.c \
     ../modules/misc/sqlite.c \
     ../modules/misc/stats/decoder.c \
     ../modules/misc/stats/demux.c \
     ../modules/misc/stats/encoder.c \
     ../modules/misc/stats/stats.c \
     ../modules/misc/stats/stats.h \
     ../modules/misc/xml/libxml.c \
     ../modules/mux/asf.c \
     ../modules/mux/avi.c \
     ../modules/mux/dummy.c \
     ../modules/mux/mp4.c \
     ../modules/mux/mpeg/bits.h \
     ../modules/mux/mpeg/csa.c \
     ../modules/mux/mpeg/csa.h \
     ../modules/mux/mpeg/pes.c \
     ../modules/mux/mpeg/pes.h \
     ../modules/mux/mpeg/ps.c \
     ../modules/mux/mpeg/ts.c \
     ../modules/mux/mpjpeg.c \
     ../modules/mux/ogg.c \
     ../modules/mux/wav.c \
     ../modules/notify/growl.m \
     ../modules/notify/notify.c \
     ../modules/packetizer/copy.c \
     ../modules/packetizer/dirac.c \
     ../modules/packetizer/flac.c \
     ../modules/packetizer/h264.c \
     ../modules/packetizer/mlp.c \
     ../modules/packetizer/mpeg4audio.c \
     ../modules/packetizer/mpeg4video.c \
     ../modules/packetizer/mpegvideo.c \
     ../modules/packetizer/vc1.c \
     ../modules/services_discovery/bonjour.c \
     ../modules/services_discovery/mediadirs.c \
     ../modules/services_discovery/mtp.c \
     ../modules/services_discovery/os2drive.c \
     ../modules/services_discovery/podcast.c \
     ../modules/services_discovery/pulse.c \
     ../modules/services_discovery/sap.c \
     ../modules/services_discovery/udev.c \
     ../modules/services_discovery/upnp.cpp \
     ../modules/services_discovery/windrive.c \
     ../modules/services_discovery/xcb_apps.c \
     ../modules/stream_filter/dash/dash.cpp \
     ../modules/stream_filter/decomp.c \
     ../modules/stream_filter/httplive.c \
     ../modules/stream_filter/record.c \
     ../modules/stream_filter/smooth/smooth.c \
     ../modules/stream_out/autodel.c \
     ../modules/stream_out/bridge.c \
     ../modules/stream_out/delay.c \
     ../modules/stream_out/description.c \
     ../modules/stream_out/display.c \
     ../modules/stream_out/dummy.c \
     ../modules/stream_out/duplicate.c \
     ../modules/stream_out/es.c \
     ../modules/stream_out/gather.c \
     ../modules/stream_out/langfromtelx.c \
     ../modules/stream_out/mosaic_bridge.c \
     ../modules/stream_out/raop.c \
     ../modules/stream_out/record.c \
     ../modules/stream_out/rtcp.c \
     ../modules/stream_out/rtp.c \
     ../modules/stream_out/rtpfmt.c \
     ../modules/stream_out/rtp.h \
     ../modules/stream_out/rtsp.c \
     ../modules/stream_out/setid.c \
     ../modules/stream_out/smem.c \
     ../modules/stream_out/standard.c \
     ../modules/stream_out/switcher.c \
     ../modules/stream_out/transcode/transcode.c \
     ../modules/text_renderer/freetype.c \
     ../modules/text_renderer/quartztext.c \
     ../modules/text_renderer/svg.c \
     ../modules/text_renderer/tdummy.c \
     ../modules/text_renderer/win32text.c \
     ../modules/video_chroma/grey_yuv.c \
     ../modules/video_chroma/i420_rgb16.c \
     ../modules/video_chroma/i420_rgb8.c \
     ../modules/video_chroma/i420_rgb.c \
     ../modules/video_chroma/i420_rgb_c.h \
     ../modules/video_chroma/i420_rgb.h \
     ../modules/video_chroma/i420_yuy2.c \
     ../modules/video_chroma/i420_yuy2.h \
     ../modules/video_chroma/i422_i420.c \
     ../modules/video_chroma/i422_yuy2.c \
     ../modules/video_chroma/i422_yuy2.h \
     ../modules/video_chroma/omxdl.c \
     ../modules/video_chroma/rv32.c \
     ../modules/video_chroma/yuy2_i420.c \
     ../modules/video_chroma/yuy2_i422.c \
     ../modules/video_filter/adjust.c \
     ../modules/video_filter/alphamask.c \
     ../modules/video_filter/anaglyph.c \
     ../modules/video_filter/antiflicker.c \
     ../modules/video_filter/atmo/AtmoCalculations.cpp \
     ../modules/video_filter/atmo/AtmoCalculations.h \
     ../modules/video_filter/atmo/AtmoConfig.cpp \
     ../modules/video_filter/atmo/AtmoConfig.h \
     ../modules/video_filter/atmo/AtmoConnection.cpp \
     ../modules/video_filter/atmo/AtmoConnection.h \
     ../modules/video_filter/atmo/atmo.cpp \
     ../modules/video_filter/atmo/AtmoDefs.h \
     ../modules/video_filter/atmo/AtmoDynData.cpp \
     ../modules/video_filter/atmo/AtmoDynData.h \
     ../modules/video_filter/atmo/AtmoExternalCaptureInput.cpp \
     ../modules/video_filter/atmo/AtmoExternalCaptureInput.h \
     ../modules/video_filter/atmo/AtmoInput.cpp \
     ../modules/video_filter/atmo/AtmoInput.h \
     ../modules/video_filter/atmo/AtmoLiveView.cpp \
     ../modules/video_filter/atmo/AtmoLiveView.h \
     ../modules/video_filter/atmo/AtmoOutputFilter.cpp \
     ../modules/video_filter/atmo/AtmoOutputFilter.h \
     ../modules/video_filter/atmo/AtmoThread.cpp \
     ../modules/video_filter/atmo/AtmoThread.h \
     ../modules/video_filter/atmo/AtmoTools.cpp \
     ../modules/video_filter/atmo/AtmoTools.h \
     ../modules/video_filter/atmo/AtmoZoneDefinition.cpp \
     ../modules/video_filter/atmo/AtmoZoneDefinition.h \
     ../modules/video_filter/audiobargraph_v.c \
     ../modules/video_filter/ball.c \
     ../modules/video_filter/blendbench.c \
     ../modules/video_filter/blend.cpp \
     ../modules/video_filter/bluescreen.c \
     ../modules/video_filter/canvas.c \
     ../modules/video_filter/chain.c \
     ../modules/video_filter/clone.c \
     ../modules/video_filter/colorthres.c \
     ../modules/video_filter/crop.c \
     ../modules/video_filter/croppadd.c \
     ../modules/video_filter/deinterlace/algo_phosphor.h \
     ../modules/video_filter/deinterlace/deinterlace.c \
     ../modules/video_filter/deinterlace/deinterlace.h \
     ../modules/video_filter/dynamicoverlay/dynamicoverlay_buffer.c \
     ../modules/video_filter/dynamicoverlay/dynamicoverlay.c \
     ../modules/video_filter/dynamicoverlay/dynamicoverlay_commands.c \
     ../modules/video_filter/dynamicoverlay/dynamicoverlay.h \
     ../modules/video_filter/dynamicoverlay/dynamicoverlay_list.c \
     ../modules/video_filter/dynamicoverlay/dynamicoverlay_queue.c \
     ../modules/video_filter/erase.c \
     ../modules/video_filter/extract.c \
     ../modules/video_filter/filter_event_info.h \
     ../modules/video_filter/filter_picture.h \
     ../modules/video_filter/gaussianblur.c \
     ../modules/video_filter/gradfun.c \
     ../modules/video_filter/gradient.c \
     ../modules/video_filter/grain.c \
     ../modules/video_filter/hqdn3d.c \
     ../modules/video_filter/invert.c \
     ../modules/video_filter/logo.c \
     ../modules/video_filter/magnify.c \
     ../modules/video_filter/marq.c \
     ../modules/video_filter/mirror.c \
     ../modules/video_filter/mosaic.c \
     ../modules/video_filter/mosaic.h \
     ../modules/video_filter/motionblur.c \
     ../modules/video_filter/motiondetect.c \
     ../modules/video_filter/opencv_example.cpp \
     ../modules/video_filter/opencv_wrapper.c \
     ../modules/video_filter/panoramix.c \
     ../modules/video_filter/posterize.c \
     ../modules/video_filter/postproc.c \
     ../modules/video_filter/psychedelic.c \
     ../modules/video_filter/puzzle.c \
     ../modules/video_filter/remoteosd.c \
     ../modules/video_filter/remoteosd_rfbproto.h \
     ../modules/video_filter/ripple.c \
     ../modules/video_filter/rotate.c \
     ../modules/video_filter/rss.c \
     ../modules/video_filter/scale.c \
     ../modules/video_filter/scene.c \
     ../modules/video_filter/sepia.c \
     ../modules/video_filter/sharpen.c \
     ../modules/video_filter/subsdelay.c \
     ../modules/video_filter/swscale.c \
     ../modules/video_filter/transform.c \
     ../modules/video_filter/wall.c \
     ../modules/video_filter/wave.c \
     ../modules/video_filter/yuvp.c \
     ../modules/video_output/aa.c \
     ../modules/video_output/androidsurface.c \
     ../modules/video_output/caca.c \
     ../modules/video_output/decklink.cpp \
     ../modules/video_output/directfb.c \
     ../modules/video_output/drawable.c \
     ../modules/video_output/egl.c \
     ../modules/video_output/fb.c \
     ../modules/video_output/gl.c \
     ../modules/video_output/glx.c \
     ../modules/video_output/ios.m \
     ../modules/video_output/kva.c \
     ../modules/video_output/macosx.m \
     ../modules/video_output/msw/direct2d.c \
     ../modules/video_output/msw/direct3d.c \
     ../modules/video_output/msw/directx.c \
     ../modules/video_output/msw/events.c \
     ../modules/video_output/msw/glwin32.c \
     ../modules/video_output/msw/wingdi.c \
     ../modules/video_output/sdl.c \
     ../modules/video_output/vdummy.c \
     ../modules/video_output/vmem.c \
     ../modules/video_output/xcb/glx.c \
     ../modules/video_output/xcb/window.c \
     ../modules/video_output/xcb/x11.c \
     ../modules/video_output/xcb/xvideo.c \
     ../modules/video_output/yuv.c \
     ../modules/visualization/goom.c \
     ../modules/visualization/projectm.cpp \
     ../modules/visualization/visual/effects.c \
     ../modules/visualization/visual/fft.c \
     ../modules/visualization/visual/fft.h \
     ../modules/visualization/visual/visual.c \
     ../modules/visualization/visual/visual.h \
     ../modules/visualization/vsxu.cpp \
     ../share/lua/http/dialogs/batch_window.html \
     ../share/lua/http/dialogs/browse_window.html \
     ../share/lua/http/dialogs/create_stream.html \
     ../share/lua/http/dialogs/equalizer_window.html \
     ../share/lua/http/dialogs/error_window.html \
     ../share/lua/http/dialogs/mosaic_window.html \
     ../share/lua/http/dialogs/offset_window.html \
     ../share/lua/http/dialogs/stream_config_window.html \
     ../share/lua/http/dialogs/stream_window.html \
     ../share/lua/http/index.html \
     ../share/lua/http/mobile_browse.html \
     ../share/lua/http/mobile_equalizer.html \
     ../share/lua/http/mobile.html \
     ../share/lua/http/mobile_view.html

CATALOGS =  ach.gmo af.gmo am.gmo ar.gmo ast.gmo be.gmo bg.gmo bn.gmo br.gmo ca.gmo cgg.gmo ckb.gmo co.gmo cs.gmo da.gmo de.gmo el.gmo en_GB.gmo es.gmo et.gmo eu.gmo fa.gmo ff.gmo fi.gmo fr.gmo fur.gmo ga.gmo gl.gmo he.gmo hi.gmo hr.gmo hu.gmo hy.gmo id.gmo is.gmo it.gmo ja.gmo ka.gmo kk.gmo km.gmo ko.gmo lg.gmo lt.gmo lv.gmo ml.gmo mk.gmo mn.gmo ms.gmo my.gmo nb.gmo ne.gmo nl.gmo nn.gmo oc.gmo pa.gmo pl.gmo ps.gmo pt_BR.gmo pt_PT.gmo ro.gmo ru.gmo si.gmo sk.gmo sl.gmo sq.gmo sr.gmo sv.gmo ta.gmo tet.gmo th.gmo tl.gmo tr.gmo uk.gmo vi.gmo wa.gmo zh_CN.gmo zh_TW.gmo zu.gmo

# Makevars gets inserted here. (Don't remove this line!)
# Makefile variables for PO directory in any package using GNU gettext.

VPATH += ../modules/gui ../modules/gui/qt4 ../modules/gui/qt4/ui

# Usually the message domain is the same as the package name.
DOMAIN = $(PACKAGE)

# These two variables depend on the location of this directory.
subdir = po
top_builddir = ..

# These options get passed to xgettext.
XGETTEXT_OPTIONS = --directory=.. --keyword=_ --keyword=N_ --keyword=_NS --keyword=_ANS --keyword=qtr --keyword=Q_ --language=C++ --keyword=vlc_ngettext:1,2 --keyword=vlc_pgettext:1c,2 --add-comments=xgettext: --from-code=UTF-8

# This is the copyright holder that gets inserted into the header of the
# $(DOMAIN).pot file.  Set this to the copyright holder of the surrounding
# package.  (Note that the msgstr strings, extracted from the package's
# sources, belong to the copyright holder of the package.)  Translators are
# expected to transfer the copyright for their translations to this person
# or entity, or to disclaim their copyright.  The empty string stands for
# the public domain; in this case the translators are expected to disclaim
# their copyright.
COPYRIGHT_HOLDER = VideoLAN

# This is the email address or URL to which the translators shall report
# bugs in the untranslated strings:
# - Strings which are not entire sentences, see the maintainer guidelines
#   in the GNU gettext documentation, section 'Preparing Strings'.
# - Strings which use unclear terms or require additional context to be
#   understood.
# - Strings which make invalid assumptions about notation of date, time or
#   money.
# - Pluralisation problems.
# - Incorrect English spelling.
# - Incorrect formatting.
# It can be your email address, or a mailing list address where translators
# can write to without being subscribed, or the URL of a web page through
# which the translators can contact you.
MSGID_BUGS_ADDRESS = vlc-devel@videolan.org

# This is the list of locale categories, beyond LC_MESSAGES, for which the
# message catalogs shall be used.  It is usually empty.
EXTRA_LOCALE_CATEGORIES =

.SUFFIXES:
.SUFFIXES: .po .gmo .mo .sed .sin .nop .po-create .po-update

.po.mo:
	@echo "$(MSGFMT) -c -o $@ $<"; \
	$(MSGFMT) -c -o t-$@ $< && mv t-$@ $@

.po.gmo:
	@lang=`echo $* | sed -e 's,.*/,,'`; \
	test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	echo "$${cdcmd}rm -f $${lang}.gmo && $(GMSGFMT) -c --statistics --verbose -o $${lang}.gmo $${lang}.po"; \
	cd $(srcdir) && rm -f $${lang}.gmo && $(GMSGFMT) -c --statistics --verbose -o t-$${lang}.gmo $${lang}.po && mv t-$${lang}.gmo $${lang}.gmo

.sin.sed:
	sed -e '/^#/d' $< > t-$@
	mv t-$@ $@


all: check-macro-version all-yes

all-yes: stamp-po
all-no:

# Ensure that the gettext macros and this Makefile.in.in are in sync.
check-macro-version:
	@test "$(GETTEXT_MACRO_VERSION)" = "0.18" \
	  || { echo "*** error: gettext infrastructure mismatch: using a Makefile.in.in from gettext version $(GETTEXT_MACRO_VERSION) but the autoconf macros are from gettext version 0.18" 1>&2; \
	       exit 1; \
	     }

# $(srcdir)/$(DOMAIN).pot is only created when needed. When xgettext finds no
# internationalized messages, no $(srcdir)/$(DOMAIN).pot is created (because
# we don't want to bother translators with empty POT files). We assume that
# LINGUAS is empty in this case, i.e. $(POFILES) and $(GMOFILES) are empty.
# In this case, stamp-po is a nop (i.e. a phony target).

# stamp-po is a timestamp denoting the last time at which the CATALOGS have
# been loosely updated. Its purpose is that when a developer or translator
# checks out the package via CVS, and the $(DOMAIN).pot file is not in CVS,
# "make" will update the $(DOMAIN).pot and the $(CATALOGS), but subsequent
# invocations of "make" will do nothing. This timestamp would not be necessary
# if updating the $(CATALOGS) would always touch them; however, the rule for
# $(POFILES) has been designed to not touch files that don't need to be
# changed.
stamp-po: $(srcdir)/$(DOMAIN).pot
	test ! -f $(srcdir)/$(DOMAIN).pot || \
	  test -z "$(GMOFILES)" || $(MAKE) $(GMOFILES)
	@test ! -f $(srcdir)/$(DOMAIN).pot || { \
	  echo "touch stamp-po" && \
	  echo timestamp > stamp-poT && \
	  mv stamp-poT stamp-po; \
	}

# Note: Target 'all' must not depend on target '$(DOMAIN).pot-update',
# otherwise packages like GCC can not be built if only parts of the source
# have been downloaded.

# This target rebuilds $(DOMAIN).pot; it is an expensive operation.
# Note that $(DOMAIN).pot is not touched if it doesn't need to be changed.
$(DOMAIN).pot-update: $(POTFILES) $(srcdir)/POTFILES.in remove-potcdate.sed
	if LC_ALL=C grep 'GNU vlc' $(top_srcdir)/* 2>/dev/null | grep -v 'libtool:' >/dev/null; then \
	  package_gnu='GNU '; \
	else \
	  package_gnu=''; \
	fi; \
	if test -n '$(MSGID_BUGS_ADDRESS)' || test '$(PACKAGE_BUGREPORT)' = '@'PACKAGE_BUGREPORT'@'; then \
	  msgid_bugs_address='$(MSGID_BUGS_ADDRESS)'; \
	else \
	  msgid_bugs_address='$(PACKAGE_BUGREPORT)'; \
	fi; \
	case `$(XGETTEXT) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	  '' | 0.[0-9] | 0.[0-9].* | 0.1[0-5] | 0.1[0-5].* | 0.16 | 0.16.[0-1]*) \
	    $(XGETTEXT) --default-domain=$(DOMAIN) --directory=$(top_srcdir) \
	      --add-comments=TRANSLATORS: $(XGETTEXT_OPTIONS)  \
	      --files-from=$(srcdir)/POTFILES.in \
	      --copyright-holder='$(COPYRIGHT_HOLDER)' \
	      --msgid-bugs-address="$$msgid_bugs_address" \
	    ;; \
	  *) \
	    $(XGETTEXT) --default-domain=$(DOMAIN) --directory=$(top_srcdir) \
	      --add-comments=TRANSLATORS: $(XGETTEXT_OPTIONS)  \
	      --files-from=$(srcdir)/POTFILES.in \
	      --copyright-holder='$(COPYRIGHT_HOLDER)' \
	      --package-name="$${package_gnu}vlc" \
	      --package-version='2.1.0-git' \
	      --msgid-bugs-address="$$msgid_bugs_address" \
	    ;; \
	esac
	test ! -f $(DOMAIN).po || { \
	  if test -f $(srcdir)/$(DOMAIN).pot; then \
	    sed -f remove-potcdate.sed < $(srcdir)/$(DOMAIN).pot > $(DOMAIN).1po && \
	    sed -f remove-potcdate.sed < $(DOMAIN).po > $(DOMAIN).2po && \
	    if cmp $(DOMAIN).1po $(DOMAIN).2po >/dev/null 2>&1; then \
	      rm -f $(DOMAIN).1po $(DOMAIN).2po $(DOMAIN).po; \
	    else \
	      rm -f $(DOMAIN).1po $(DOMAIN).2po $(srcdir)/$(DOMAIN).pot && \
	      mv $(DOMAIN).po $(srcdir)/$(DOMAIN).pot; \
	    fi; \
	  else \
	    mv $(DOMAIN).po $(srcdir)/$(DOMAIN).pot; \
	  fi; \
	}

# This rule has no dependencies: we don't need to update $(DOMAIN).pot at
# every "make" invocation, only create it when it is missing.
# Only "make $(DOMAIN).pot-update" or "make dist" will force an update.
$(srcdir)/$(DOMAIN).pot:
	$(MAKE) $(DOMAIN).pot-update

# This target rebuilds a PO file if $(DOMAIN).pot has changed.
# Note that a PO file is not touched if it doesn't need to be changed.
$(POFILES): $(srcdir)/$(DOMAIN).pot
	@lang=`echo $@ | sed -e 's,.*/,,' -e 's/\.po$$//'`; \
	if test -f "$(srcdir)/$${lang}.po"; then \
	  test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	  echo "$${cdcmd}$(MSGMERGE_UPDATE) $(MSGMERGE_OPTIONS) --lang=$${lang} $${lang}.po $(DOMAIN).pot"; \
	  cd $(srcdir) \
	    && { case `$(MSGMERGE_UPDATE) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	           '' | 0.[0-9] | 0.[0-9].* | 0.1[0-7] | 0.1[0-7].*) \
	             $(MSGMERGE_UPDATE) $(MSGMERGE_OPTIONS) $${lang}.po $(DOMAIN).pot;; \
	           *) \
	             $(MSGMERGE_UPDATE) $(MSGMERGE_OPTIONS) --lang=$${lang} $${lang}.po $(DOMAIN).pot;; \
	         esac; \
	       }; \
	else \
	  $(MAKE) $${lang}.po-create; \
	fi


install: install-exec install-data
install-exec:
install-data: install-data-yes
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  $(mkdir_p) $(DESTDIR)$(gettextsrcdir); \
	  for file in $(DISTFILES.common) Makevars.template; do \
	    $(INSTALL_DATA) $(srcdir)/$$file \
			    $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	  for file in Makevars; do \
	    rm -f $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	else \
	  : ; \
	fi
install-data-no: all
install-data-yes: all
	@catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  dir=$(localedir)/$$lang/LC_MESSAGES; \
	  $(mkdir_p) $(DESTDIR)$$dir; \
	  if test -r $$cat; then realcat=$$cat; else realcat=$(srcdir)/$$cat; fi; \
	  $(INSTALL_DATA) $$realcat $(DESTDIR)$$dir/$(DOMAIN).mo; \
	  echo "installing $$realcat as $(DESTDIR)$$dir/$(DOMAIN).mo"; \
	  for lc in '' $(EXTRA_LOCALE_CATEGORIES); do \
	    if test -n "$$lc"; then \
	      if (cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc 2>/dev/null) | grep ' -> ' >/dev/null; then \
	        link=`cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc | sed -e 's/^.* -> //'`; \
	        mv $(DESTDIR)$(localedir)/$$lang/$$lc $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	        mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        (cd $(DESTDIR)$(localedir)/$$lang/$$lc.old && \
	         for file in *; do \
	           if test -f $$file; then \
	             ln -s ../$$link/$$file $(DESTDIR)$(localedir)/$$lang/$$lc/$$file; \
	           fi; \
	         done); \
	        rm -f $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	      else \
	        if test -d $(DESTDIR)$(localedir)/$$lang/$$lc; then \
	          :; \
	        else \
	          rm -f $(DESTDIR)$(localedir)/$$lang/$$lc; \
	          mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        fi; \
	      fi; \
	      rm -f $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	      ln -s ../LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo 2>/dev/null || \
	      ln $(DESTDIR)$(localedir)/$$lang/LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo 2>/dev/null || \
	      cp -p $(DESTDIR)$(localedir)/$$lang/LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	      echo "installing $$realcat link as $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo"; \
	    fi; \
	  done; \
	done

install-strip: install

installdirs: installdirs-exec installdirs-data
installdirs-exec:
installdirs-data: installdirs-data-yes
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  $(mkdir_p) $(DESTDIR)$(gettextsrcdir); \
	else \
	  : ; \
	fi
installdirs-data-no:
installdirs-data-yes:
	@catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  dir=$(localedir)/$$lang/LC_MESSAGES; \
	  $(mkdir_p) $(DESTDIR)$$dir; \
	  for lc in '' $(EXTRA_LOCALE_CATEGORIES); do \
	    if test -n "$$lc"; then \
	      if (cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc 2>/dev/null) | grep ' -> ' >/dev/null; then \
	        link=`cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc | sed -e 's/^.* -> //'`; \
	        mv $(DESTDIR)$(localedir)/$$lang/$$lc $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	        mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        (cd $(DESTDIR)$(localedir)/$$lang/$$lc.old && \
	         for file in *; do \
	           if test -f $$file; then \
	             ln -s ../$$link/$$file $(DESTDIR)$(localedir)/$$lang/$$lc/$$file; \
	           fi; \
	         done); \
	        rm -f $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	      else \
	        if test -d $(DESTDIR)$(localedir)/$$lang/$$lc; then \
	          :; \
	        else \
	          rm -f $(DESTDIR)$(localedir)/$$lang/$$lc; \
	          mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        fi; \
	      fi; \
	    fi; \
	  done; \
	done

# Define this as empty until I found a useful application.
installcheck:

uninstall: uninstall-exec uninstall-data
uninstall-exec:
uninstall-data: uninstall-data-yes
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  for file in $(DISTFILES.common) Makevars.template; do \
	    rm -f $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	else \
	  : ; \
	fi
uninstall-data-no:
uninstall-data-yes:
	catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  for lc in LC_MESSAGES $(EXTRA_LOCALE_CATEGORIES); do \
	    rm -f $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	  done; \
	done

check: all

info dvi ps pdf html tags TAGS ctags CTAGS ID:

mostlyclean:
	rm -f remove-potcdate.sed
	rm -f stamp-poT
	rm -f core core.* $(DOMAIN).po $(DOMAIN).1po $(DOMAIN).2po *.new.po
	rm -fr *.o

clean: mostlyclean

distclean: clean
	rm -f Makefile Makefile.in POTFILES *.mo

maintainer-clean: distclean
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."
	rm -f stamp-po $(GMOFILES)

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
dist distdir:
	$(MAKE) update-po
	@$(MAKE) dist2
# This is a separate target because 'update-po' must be executed before.
dist2: stamp-po $(DISTFILES)
	dists="$(DISTFILES)"; \
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  dists="$$dists Makevars.template"; \
	fi; \
	if test -f $(srcdir)/$(DOMAIN).pot; then \
	  dists="$$dists $(DOMAIN).pot stamp-po"; \
	fi; \
	if test -f $(srcdir)/ChangeLog; then \
	  dists="$$dists ChangeLog"; \
	fi; \
	for i in 0 1 2 3 4 5 6 7 8 9; do \
	  if test -f $(srcdir)/ChangeLog.$$i; then \
	    dists="$$dists ChangeLog.$$i"; \
	  fi; \
	done; \
	if test -f $(srcdir)/LINGUAS; then dists="$$dists LINGUAS"; fi; \
	for file in $$dists; do \
	  if test -f $$file; then \
	    cp -p $$file $(distdir) || exit 1; \
	  else \
	    cp -p $(srcdir)/$$file $(distdir) || exit 1; \
	  fi; \
	done

update-po: Makefile
	$(MAKE) $(DOMAIN).pot-update
	test -z "$(UPDATEPOFILES)" || $(MAKE) $(UPDATEPOFILES)
	$(MAKE) update-gmo

# General rule for creating PO files.

.nop.po-create:
	@lang=`echo $@ | sed -e 's/\.po-create$$//'`; \
	echo "File $$lang.po does not exist. If you are a translator, you can create it through 'msginit'." 1>&2; \
	exit 1

# General rule for updating PO files.

.nop.po-update:
	@lang=`echo $@ | sed -e 's/\.po-update$$//'`; \
	if test "$(PACKAGE)" = "gettext-tools"; then PATH=`pwd`/../src:$$PATH; fi; \
	tmpdir=`pwd`; \
	echo "$$lang:"; \
	test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	echo "$${cdcmd}$(MSGMERGE) $(MSGMERGE_OPTIONS) --lang=$$lang $$lang.po $(DOMAIN).pot -o $$lang.new.po"; \
	cd $(srcdir); \
	if { case `$(MSGMERGE) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	       '' | 0.[0-9] | 0.[0-9].* | 0.1[0-7] | 0.1[0-7].*) \
	         $(MSGMERGE) $(MSGMERGE_OPTIONS) -o $$tmpdir/$$lang.new.po $$lang.po $(DOMAIN).pot;; \
	       *) \
	         $(MSGMERGE) $(MSGMERGE_OPTIONS) --lang=$$lang -o $$tmpdir/$$lang.new.po $$lang.po $(DOMAIN).pot;; \
	     esac; \
	   }; then \
	  if cmp $$lang.po $$tmpdir/$$lang.new.po >/dev/null 2>&1; then \
	    rm -f $$tmpdir/$$lang.new.po; \
	  else \
	    if mv -f $$tmpdir/$$lang.new.po $$lang.po; then \
	      :; \
	    else \
	      echo "msgmerge for $$lang.po failed: cannot move $$tmpdir/$$lang.new.po to $$lang.po" 1>&2; \
	      exit 1; \
	    fi; \
	  fi; \
	else \
	  echo "msgmerge for $$lang.po failed!" 1>&2; \
	  rm -f $$tmpdir/$$lang.new.po; \
	fi

$(DUMMYPOFILES):

update-gmo: Makefile $(GMOFILES)
	@:

# Recreate Makefile by invoking config.status. Explicitly invoke the shell,
# because execution permission bits may not work on the current file system.
# Use /bin/bash, which is the shell determined by autoconf for the use by its
# scripts, not $(SHELL) which is hardwired to /bin/sh and may be deficient.
Makefile: Makefile.in.in Makevars $(top_builddir)/config.status POTFILES.in LINGUAS
	cd $(top_builddir) \
	  && /bin/bash ./config.status $(subdir)/$@.in po-directories

force:

# Tell versions [3.59,3.63) of GNU make not to export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
# Special Makefile rules for English message catalogs with quotation marks.

DISTFILES.common.extra1 = quot.sed boldquot.sed en@quot.header en@boldquot.header insert-header.sin Rules-quot

.SUFFIXES: .insert-header .po-update-en

en@quot.po-create:
	$(MAKE) en@quot.po-update
en@boldquot.po-create:
	$(MAKE) en@boldquot.po-update

en@quot.po-update: en@quot.po-update-en
en@boldquot.po-update: en@boldquot.po-update-en

.insert-header.po-update-en:
	@lang=`echo $@ | sed -e 's/\.po-update-en$$//'`; \
	if test "$(PACKAGE)" = "gettext"; then PATH=`pwd`/../src:$$PATH; GETTEXTLIBDIR=`cd $(top_srcdir)/src && pwd`; export GETTEXTLIBDIR; fi; \
	tmpdir=`pwd`; \
	echo "$$lang:"; \
	ll=`echo $$lang | sed -e 's/@.*//'`; \
	LC_ALL=C; export LC_ALL; \
	cd $(srcdir); \
	if $(MSGINIT) -i $(DOMAIN).pot --no-translator -l $$lang -o - 2>/dev/null | sed -f $$tmpdir/$$lang.insert-header | $(MSGCONV) -t UTF-8 | $(MSGFILTER) sed -f `echo $$lang | sed -e 's/.*@//'`.sed 2>/dev/null > $$tmpdir/$$lang.new.po; then \
	  if cmp $$lang.po $$tmpdir/$$lang.new.po >/dev/null 2>&1; then \
	    rm -f $$tmpdir/$$lang.new.po; \
	  else \
	    if mv -f $$tmpdir/$$lang.new.po $$lang.po; then \
	      :; \
	    else \
	      echo "creation of $$lang.po failed: cannot move $$tmpdir/$$lang.new.po to $$lang.po" 1>&2; \
	      exit 1; \
	    fi; \
	  fi; \
	else \
	  echo "creation of $$lang.po failed!" 1>&2; \
	  rm -f $$tmpdir/$$lang.new.po; \
	fi

en@quot.insert-header: insert-header.sin
	sed -e '/^#/d' -e 's/HEADER/en@quot.header/g' $(srcdir)/insert-header.sin > en@quot.insert-header

en@boldquot.insert-header: insert-header.sin
	sed -e '/^#/d' -e 's/HEADER/en@boldquot.header/g' $(srcdir)/insert-header.sin > en@boldquot.insert-header

mostlyclean: mostlyclean-quot
mostlyclean-quot:
	rm -f *.insert-header
