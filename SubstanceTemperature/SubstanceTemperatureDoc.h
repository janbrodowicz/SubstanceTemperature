#pragma once


class CSubstanceTemperatureDoc : public CDocument
{
	protected:
		DECLARE_DYNCREATE(CSubstanceTemperatureDoc)

	public:
		virtual void Serialize(CArchive& ar);

	protected:
		DECLARE_MESSAGE_MAP()
};
