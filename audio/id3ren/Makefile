# Created by: Joao Carlos Mendes Luis <jonny@jonny.eng.br>
# $FreeBSD$

PORTNAME=	id3ren
PORTVERSION=	1.1b0
CATEGORIES=	audio
MASTER_SITES=	http://cbothamy.free.fr/projects/id3ren/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mpeg Audio Layer 3 util: rename files, edit tags, search, etc

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-11-26

PLIST_FILES=	bin/id3ren
MAN1=		id3ren.1
MANCOMPRESSED=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/src/id3ren.c ${WRKSRC}/src/id3misc.c
	${RM} ${WRKSRC}/src/id3ren

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS ChangeLog FEATURES FEEDBACK INSTALL PORTS \
		README THANKS TODO USAGE

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
