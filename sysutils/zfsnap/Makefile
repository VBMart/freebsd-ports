# Created by: Aldis Berjoza <aldis@bsdroot.lv>
# $FreeBSD$

PORTNAME=	zfsnap
PORTVERSION=	1.10.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://files.bsdroot.lv/my/FreeBSD/distfiles/
DISTNAME=	zfSnap-${PORTVERSION}

MAINTAINER=	graudeejs@gmail.com
COMMENT=	Simple sh script to make zfs rolling snaphosts with cron

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/graudeejs-zfSnap-${REV}
REV=		e9e56ff

PERIODICDIR?=	${PREFIX}/etc/periodic
PLIST_SUB+=	PERIODICDIR="${PERIODICDIR:S,^${PREFIX}/,,}"

do-patch:
.for period in hourly daily weekly monthly reboot
	@${SED} -e "s/xPERIODICx/${period}/g" -e "s#xPREFIXx#${PREFIX}/sbin#g" ${WRKSRC}/xPERIODICx_zfSnap.sh > ${WRKSRC}/${period}_zfSnap.sh
.endfor
.for period in hourly daily weekly monthly
	@${SED} -e "s/xPERIODICx/${period}/g" -e "s#xPREFIXx#${PREFIX}/sbin#g" ${WRKSRC}/xPERIODICx_zfSnap_delete.sh > ${WRKSRC}/${period}_zfSnap_delete.sh
.endfor

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/zfSnap.sh ${PREFIX}/sbin/zfSnap
.for period in hourly daily weekly monthly reboot
	@${MKDIR} ${PERIODICDIR}/${period}
	@${INSTALL_SCRIPT} ${WRKSRC}/${period}_zfSnap.sh ${PERIODICDIR}/${period}/402.zfSnap
.endfor
.for period in hourly daily weekly monthly
	@${INSTALL_SCRIPT} ${WRKSRC}/${period}_zfSnap_delete.sh ${PERIODICDIR}/${period}/403.zfSnap_delete
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
