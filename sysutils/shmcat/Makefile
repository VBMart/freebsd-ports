# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	shmcat
PORTVERSION=	1.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Simple tool that dumps System V shared memory segments

USE_BZIP2=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-libintl-prefix=${LOCALBASE}

OPTIONS_DEFINE=	NLS

MAN1=		shmcat.1 \
		ftok.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
MANLANG=	"" de
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
