# SPDX-FileCopyrightText: 2025 Alicipy <dev@stefankraus.org>
#
# SPDX-License-Identifier: Apache-2.0

ARG CI_IMAGE_VERSION=v0.28.4

FROM ghcr.io/zephyrproject-rtos/ci:${CI_IMAGE_VERSION} AS build

RUN <<EOF
    cd /opt/toolchains/zephyr-*
    rm -rf aarch64-* arc-* arc64-* microblazeel-* mips-* nios2-* riscv64-* rx-* sparc-* xtensa-* \
        sysroots/x86_64-pokysdk-linux/usr/xilinx
EOF

FROM ghcr.io/zephyrproject-rtos/ci-base:${CI_IMAGE_VERSION}
ENV ZEPHYR_TOOLCHAIN_VARIANT=zephyr

COPY --from=build /opt/toolchains/ /opt/toolchains/
