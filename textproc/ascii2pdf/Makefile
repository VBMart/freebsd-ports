# Created by: petef@databits.net
# $FreeBSD$

PORTNAME=	ascii2pdf
PORTVERSION= 	0.9.1
CATEGORIES=	textproc
MASTER_SITES=	http://bulldog.tzo.org/ascii2pdf/
DISTNAME=	${PORTNAME}-0.9.1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A perl script to convert text files to PDF files

RUN_DEPENDS=    p5-PDF-Create>=0:${PORTSDIR}/textproc/p5-PDF-Create

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-11-26

NO_BUILD=	yes
USE_PERL5=	yes
PLIST_FILES=	bin/ascii2pdf

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/ascii2pdf ${PREFIX}/bin

.include <bsd.port.post.mk>
