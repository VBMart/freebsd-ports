# New ports collection makefile for:	XML-SAX-ExpatXS
# Date created:	   30 March 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-SAX-ExpatXS
PORTVERSION=	1.32
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PerlSAX2 XS extension to Expat parser

RUN_DEPENDS=	p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	EXPATLIBPATH=${LOCALBASE}/lib \
		EXPATINCPATH=${LOCALBASE}/include </dev/null

MAN3=		XML::SAX::ExpatXS.3 XML::SAX::ExpatXS::Encoding.3 \
		XML::SAX::ExpatXS::Preload.3

.include <bsd.port.mk>
