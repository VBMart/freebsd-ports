# New ports collection makefile for:	grsync
# Date created:		24 August 2007
# Whom:			Ganael Laplanche <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	grsync
PORTVERSION=	1.2.2
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.opbyte.it/release/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	GTK frontend for rsync

LICENSE=	GPLv2

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync \
		bash:${PORTSDIR}/shells/bash

USE_GNOME=	gtk20 desktopfileutils
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-unity
USE_GMAKE=	yes

INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		grsync.1 grsync-batch.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		${WRKSRC}/src/grsync-batch
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} 's/^ALL_LINGUAS=.*/ALL_LINGUAS=""/' \
		${WRKSRC}/configure
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
