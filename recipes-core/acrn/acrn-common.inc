SUMMARY = "A Type 1 hypervisor stack, running directly on the bare-metal hardware"
HOMEPAGE = "https://projectacrn.org/"
LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = "file://LICENSE;md5=5732af37bf18525ed9d2b16985054901"

SRC_URI = "git://github.com/projectacrn/acrn-hypervisor.git;branch=release_1.5 \
           file://paths.patch \
           file://0001-hypervisor-Makefile-do-not-strip.patch \
           file://0001-acrn-config-append-kconfig-setting-on-new-board.patch \
           file://Fix-build-issue-if-the-ld-is-updated-to-2.34.patch \
"

# Snapshot tags are of the format:
# acrn-<year>w<week>.<day>-<timestamp><pass|fail>
PV = "1.5.1"
SRCREV = "e13c6dec9215701117bc76eacb09ad4f6ad55306"

UPSTREAM_CHECK_GITTAGREGEX = "^v(?P<pver>\d+(\.\d+)+)$"

S = "${WORKDIR}/git/"

# 1 for release build, 0 for debug build.
ACRN_RELEASE ?= "0"

EXTRA_OEMAKE += "RELEASE=${ACRN_RELEASE} \
                 SYSROOT=${STAGING_DIR_TARGET} \
                 O=${B} \
                 DESTDIR=${D} \
                 prefix=${prefix} \
                 bindir=${bindir} \
                 libdir=${libdir} \
                 datadir=${datadir} \
                 includedir=${includedir} \
                 systemd_unitdir=${systemd_unitdir}"


# acrn supports build objects out-of-tree but builds must be performed from
# inside the source
B = "${WORKDIR}/build/"
do_configure[cleandirs] = "${B}"
do_configure[dirs] = "${S}"
do_compile[dirs] = "${S}"
do_install[dirs] = "${S}"
