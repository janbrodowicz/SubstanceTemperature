
#include "pch.h"
#include "SubstanceTemperatureDoc.h"

IMPLEMENT_DYNCREATE(CSubstanceTemperatureDoc, CDocument)

BEGIN_MESSAGE_MAP(CSubstanceTemperatureDoc, CDocument)
END_MESSAGE_MAP()

void CSubstanceTemperatureDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: W tym miejscu dodaj kod przechowywania
	}
	else
	{
		// TODO: W tym miejscu dodaj kod ładujący
	}
}
