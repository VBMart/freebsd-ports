# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fcitx-hangul
PORTVERSION=	0.1.2
CATEGORIES=	korean
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	fcitx
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Hangul support for Fcitx

LICENSE=	GPLv2

LIB_DEPENDS=	fcitx-config:${PORTSDIR}/chinese/fcitx \
		hangul:${PORTSDIR}/korean/libhangul

USE_XZ=		yes
USE_GETTEXT=	yes
USE_CMAKE=	yes
USE_GNOME=	intltool
INSTALLS_ICONS=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

.include <bsd.port.mk>
