# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	aifad
PORTVERSION=	1.0.27
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.ocaml.info/ocaml_sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Machine learning system

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-11-26

BUILD_DEPENDS=	${SA_DIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre \
		${SA_DIR}/res/res.a:${PORTSDIR}/devel/ocaml-res \
		${SA_DIR}/cfg/cfg.a:${PORTSDIR}/devel/ocaml-cfg
LIB_DEPENDS=	pcre.1:${PORTSDIR}/devel/pcre

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=yes

ALL_TARGET=	opt
SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

DOCS=	README.txt TODO

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin/

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}/
.endif

.include <bsd.port.post.mk>
