## This is a automake file, part of Unidata's netCDF package.
# Copyright 2018, see the COPYRIGHT file for more information.

# This automake file generates the Makefile to build the include
# directory.

# Ed Hartnett, Dennis Heimbigner, Ward Fisher

include_HEADERS = netcdf.h netcdf_meta.h netcdf_mem.h netcdf_aux.h	\
netcdf_filter.h netcdf_filter_build.h netcdf_filter_hdf5_build.h netcdf_dispatch.h netcdf_json.h

if BUILD_PARALLEL
include_HEADERS += netcdf_par.h
endif

noinst_HEADERS = nc_logging.h nc_tests.h fbits.h nc.h nclist.h		\
ncuri.h ncutf8.h ncdispatch.h ncdimscale.h netcdf_f.h err_macros.h	\
ncbytes.h nchashmap.h ceconstraints.h rnd.h nclog.h ncconfigure.h	\
nc4internal.h nctime.h nc3internal.h onstack.h ncrc.h ncauth.h		\
ncoffsets.h nctestserver.h nc4dispatch.h nc3dispatch.h ncexternl.h	\
ncpathmgr.h ncindex.h hdf4dispatch.h hdf5internal.h nc_provenance.h	\
hdf5dispatch.h ncmodel.h isnan.h nccrc.h ncexhash.h ncxcache.h          \
ncfilter.h ncjson.h ncxml.h ncs3sdk.h

if USE_DAP
noinst_HEADERS += ncdap.h
endif

if ENABLE_BYTERANGE
noinst_HEADERS += nchttp.h
endif

EXTRA_DIST = CMakeLists.txt XGetopt.h netcdf_meta.h.in netcdf_dispatch.h.in

# Give the recipe for rebuilding netcdf_json.h
makencjson::
	sed -e 's/NCJSON_H/NETCDF_JSON_H/' -e '/ncjson.h/d' <${srcdir}/ncjson.h > netcdf_json.h
	sed -e '/ncjson.h/d' < ${srcdir}/../libdispatch/ncjson.c >> netcdf_json.h
