# New ports collection makefile for:	p5-Net-Twitter-Lite
# Date created:				Aug  2, 2009
# Whom:					Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Twitter-Lite
PORTVERSION=	0.11002
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	max@FreeBSD.org
COMMENT=	A perl interface to the Twitter API

BUILD_DEPENDS=	p5-JSON>=2.02:${PORTSDIR}/converters/p5-JSON \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Memoize>=0:${PORTSDIR}/devel/p5-Memoize \
		p5-URI>=1.4:${PORTSDIR}/net/p5-URI \
		p5-Net-OAuth>=0.25:${PORTSDIR}/net/p5-Net-OAuth \
		p5-Crypt-SSLeay>=0.5:${PORTSDIR}/security/p5-Crypt-SSLeay
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=		Net::Twitter::Lite.3 Net::Twitter::Lite::Error.3

.include <bsd.port.mk>
