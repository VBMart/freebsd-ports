# New ports collection makefile for:	apache-solr
# Date created:		2009-03-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	apache-solr
PORTVERSION=	3.6.0
CATEGORIES=	textproc java
MASTER_SITES=	APACHE
MASTER_SITE_SUBDIR=	lucene/solr/${PORTVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gaod@hychen.org
COMMENT=	High performance search server built using Lucene Java

LICENSE=	AL2
JAVA_VERSION=	1.5+
NO_BUILD=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
USE_JAVA=	yes
PORTEXAMPLES=	*

do-install:
	cd ${WRKSRC}/dist && ${COPYTREE_SHARE} \* ${JAVAJARDIR}
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/example && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
