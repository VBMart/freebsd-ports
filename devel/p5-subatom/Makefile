# New ports collection makefile for:	p5-subatom
# Date created:		2006-09-26
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	subatom
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HDM
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Produce an atom feed from subversion commits

BUILD_DEPENDS=	p5-XML-Atom-SimpleFeed>=0:${PORTSDIR}/textproc/p5-XML-Atom-SimpleFeed
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes
PLIST_FILES=	bin/subatom

MAN1=		subatom.1

.include <bsd.port.mk>
