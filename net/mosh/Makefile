# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mosh
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://cloud.github.com/downloads/keithw/${PORTNAME}/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Mobile terminal that supports intermittent connectivity

LICENSE=	GPLv3

LIB_DEPENDS=	protobuf:${PORTSDIR}/devel/protobuf
RUN_DEPENDS=	p5-IO-Tty>=0:${PORTSDIR}/devel/p5-IO-Tty

USE_PERL5_RUN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-utempter
CONFIGURE_ENV+=	OPENSSL_CFLAGS="-I${OPENSSLINC}" OPENSSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
INSTALL_TARGET=	install-strip
USE_OPENSSL=	yes
USE_PKGCONFIG=	build

LATEST_LINK=	mosh-term

CONFLICTS_INSTALL=	mosh-0.[2-9].*

PLIST_FILES=	bin/mosh bin/mosh-server bin/mosh-client
MAN1=		mosh-client.1 mosh-server.1 mosh.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900004
LIB_DEPENDS+=	utempter:${PORTSDIR}/sysutils/libutempter
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
