# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	gq
PORTVERSION=	1.3.4
PORTREVISION=	8
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}client/GQ%20Unstable/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK-based LDAP client

LIB_DEPENDS=	gnome-keyring:${PORTSDIR}/security/gnome-keyring

OPTIONS_DEFINE=	DND CACHE
OPTIONS_DEFAULT=	DND CACHE
DND_DESC=	Enable Drag and drop support in browse mode
CACHE_DESC=	Support the OpenLDAP experimental client cache

USE_GNOME=	libglade2 gnomedocutils
USE_OPENSSL=	yes
USE_OPENLDAP=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ldap-prefix=${LOCALBASE}

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDND}
CONFIGURE_ARGS+=	--enable-browser-dnd
.endif

.if ${PORT_OPTIONS:MCACHE}
CONFIGURE_ARGS+=	--enable-cache
.endif

.include <bsd.port.mk>
