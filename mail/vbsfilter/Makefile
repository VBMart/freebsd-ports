# $FreeBSD$

PORTNAME=	vbsfilter
PORTVERSION=	1.15
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://aeschi.ch.eu.org/milter/
EXTRACT_SUFX=	.c
EXTRACT_ONLY=	# empty

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A vbs-attachment filter for Sendmail Milter

LICENSE=	GPLv2

USE_RC_SUBR=	vbsfilter
PLIST_FILES=	libexec/vbsfilter

CTARGETS+=	vbsfilter-${PORTVERSION}
LIBS+=		${PTHREAD_LIBS}
LIBS+=		-lmilter
CFLAGS+=	-Wall ${PTHREAD_CFLAGS:S=""==}

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.if defined(SENDMAIL_WITH_SFIO)
LIBS+=		-lsfio
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${_DISTDIR}vbsfilter-${PORTVERSION}.c ${WRKSRC}

.for i in ${CTARGETS}
${i}:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} ${LDFLAGS} -o ${i} ${i}.c ${LIBS} ${FLAGS}

.endfor

do-build:	${CTARGETS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vbsfilter-${PORTVERSION} \
		${PREFIX}/libexec/vbsfilter

.include <bsd.port.post.mk>
