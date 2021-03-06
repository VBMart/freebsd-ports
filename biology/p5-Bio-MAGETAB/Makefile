# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Bio-MAGETAB
PORTVERSION=	1.26
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A data model and utility API for the MAGE-TAB format

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Date-Manip>=5.44:${PORTSDIR}/devel/p5-Date-Manip \
		p5-DateTime>=0.43.02:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-DateManip>=0.04:${PORTSDIR}/devel/p5-DateTime-Format-DateManip \
		p5-Email-Valid>=0.179:${PORTSDIR}/mail/p5-Email-Valid \
		p5-Moose>=0.43:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-FollowPBP>=0.04:${PORTSDIR}/devel/p5-MooseX-FollowPBP \
		p5-MooseX-Types>=0.10:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Params-Coerce>=0.14:${PORTSDIR}/devel/p5-Params-Coerce \
		p5-Parse-RecDescent>=1.965.001:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-Text-CSV_XS>=0.32:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		p5-URI>=1.35:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0.26:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN3=		Bio::MAGETAB.3 \
		Bio::MAGETAB::ArrayDesign.3 \
		Bio::MAGETAB::Assay.3 \
		Bio::MAGETAB::BaseClass.3 \
		Bio::MAGETAB::Comment.3 \
		Bio::MAGETAB::CompositeElement.3 \
		Bio::MAGETAB::Contact.3 \
		Bio::MAGETAB::ControlledTerm.3 \
		Bio::MAGETAB::Data.3 \
		Bio::MAGETAB::DataAcquisition.3 \
		Bio::MAGETAB::DataFile.3 \
		Bio::MAGETAB::DataMatrix.3 \
		Bio::MAGETAB::DatabaseEntry.3 \
		Bio::MAGETAB::DesignElement.3 \
		Bio::MAGETAB::Edge.3 \
		Bio::MAGETAB::Event.3 \
		Bio::MAGETAB::Extract.3 \
		Bio::MAGETAB::Factor.3 \
		Bio::MAGETAB::FactorValue.3 \
		Bio::MAGETAB::Feature.3 \
		Bio::MAGETAB::Investigation.3 \
		Bio::MAGETAB::LabeledExtract.3 \
		Bio::MAGETAB::Material.3 \
		Bio::MAGETAB::MatrixColumn.3 \
		Bio::MAGETAB::MatrixRow.3 \
		Bio::MAGETAB::Measurement.3 \
		Bio::MAGETAB::Node.3 \
		Bio::MAGETAB::Normalization.3 \
		Bio::MAGETAB::ParameterValue.3 \
		Bio::MAGETAB::Protocol.3 \
		Bio::MAGETAB::ProtocolApplication.3 \
		Bio::MAGETAB::ProtocolParameter.3 \
		Bio::MAGETAB::Publication.3 \
		Bio::MAGETAB::Reporter.3 \
		Bio::MAGETAB::SDRF.3 \
		Bio::MAGETAB::SDRFRow.3 \
		Bio::MAGETAB::Sample.3 \
		Bio::MAGETAB::Source.3 \
		Bio::MAGETAB::TermSource.3 \
		Bio::MAGETAB::Types.3 \
		Bio::MAGETAB::Util::Builder.3 \
		Bio::MAGETAB::Util::DBLoader.3 \
		Bio::MAGETAB::Util::Persistence.3 \
		Bio::MAGETAB::Util::Reader.3 \
		Bio::MAGETAB::Util::Reader::ADF.3 \
		Bio::MAGETAB::Util::Reader::DataMatrix.3 \
		Bio::MAGETAB::Util::Reader::IDF.3 \
		Bio::MAGETAB::Util::Reader::SDRF.3 \
		Bio::MAGETAB::Util::Reader::Tabfile.3 \
		Bio::MAGETAB::Util::Reader::TagValueFile.3 \
		Bio::MAGETAB::Util::RewriteAE.3 \
		Bio::MAGETAB::Util::Writer.3 \
		Bio::MAGETAB::Util::Writer::ADF.3 \
		Bio::MAGETAB::Util::Writer::GraphViz.3 \
		Bio::MAGETAB::Util::Writer::IDF.3 \
		Bio::MAGETAB::Util::Writer::SDRF.3 \
		Bio::MAGETAB::Util::Writer::Tabfile.3

post-patch:
	@${REINPLACE_CMD} -e '/^auto_install;/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
