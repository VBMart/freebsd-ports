# New ports collection makefile for:	asterisk-addons
# Date created:				23 March 2006
# Whom:					Fabian Gast <fgast@only640k.org>
#
# $FreeBSD$
#

PORTNAME=	asterisk14
PORTVERSION=	1.4.13
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/asterisk/ \
		http://downloads.asterisk.org/pub/telephony/asterisk/old-releases/
PKGNAMESUFFIX=	-addons
DISTNAME=	asterisk${PKGNAMESUFFIX}-${DISTVERSION}

MAINTAINER=	bamby@sippysoft.com
COMMENT=	GPL modules for the Asterisk Open Source PBX

BUILD_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk14
RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk14

OPTIONS=	SAMPLE_CONFIG	"Install sample configuration files" off

ONLY_FOR_ARCHS=	i386 amd64 powerpc
USE_AUTOTOOLS=	libtool
USE_MYSQL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_SAMPLE_CONFIG)
PLIST_SUB+=	SAMPLE_CONFIG=""
.else
PLIST_SUB+=	SAMPLE_CONFIG="@comment "
.endif

pre-configure:
	if ${GREP} -sq fixup_codecs ${LOCALBASE}/include/asterisk/channel.h; \
	then \
		${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/codecnego.diff; \
	fi

post-install:
.if defined(WITH_SAMPLE_CONFIG)
	@cd ${WRKSRC} && ${GMAKE} samples
.endif

.include <bsd.port.post.mk>
