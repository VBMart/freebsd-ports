# Created by: Makoto Matsushita <matusita@FreeBSD.org>
# $FreeBSD$

PORTNAME=	irchat-jp
PORTVERSION=	26.d
PORTREVISION=	10
CATEGORIES=	irc elisp
MASTER_SITES=	http://www.ircnet.jp/dist/irchat/:master \
		${MASTER_SITE_LOCAL:S/$/:backup/}
MASTER_SITE_SUBDIR= "":master matusita/${PORTNAME}/:backup
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}
DISTFILES=	${DISTNAME}.tgz:master,backup

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC client for Emacs, derived from irchat

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-11-26

RUN_DEPENDS=	${LOCALBASE}/bin/dcc:${PORTSDIR}/irc/dcc

NO_WRKSUBDIR=	YES
NO_BUILD=	YES
USE_EMACS=	YES

LISPDIR?=	${EMACS_SITE_LISPDIR}/${PORTNAME}
LISPFILES=	irchat-commands.el irchat-ctcp.el irchat-dcc.el \
		irchat-filter.el irchat-globals.el irchat-handle.el \
		irchat-inlines.el irchat-iso-2022-jp.el irchat-misc.el \
		irchat-original-copyright.el irchat-vars.el irchat.el

PLIST_DIRS=	${LISPDIR}
.for f in ${LISPFILES}
PLIST_FILES+=	${LISPDIR}/${f}
.endfor

do-install:
	${MKDIR} ${PREFIX}/${LISPDIR}
.for f in ${LISPFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${LISPDIR}
.endfor

.include <bsd.port.mk>
