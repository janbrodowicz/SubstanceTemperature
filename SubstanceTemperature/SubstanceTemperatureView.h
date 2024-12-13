#pragma once

#include "SubstancesResource.h"
#include "SubstanceNamesContainer.h"
#include "InstrumentsContainer.h"



class CSubstanceTemperatureView : public CView
{
protected:
	DECLARE_DYNCREATE(CSubstanceTemperatureView)

protected:
	// Static texts
	CStatic m_instrumentID_text;
	CStatic m_substanceName_text;
	CStatic m_nominalTemp_text;
	CStatic m_meassuredTemp_text;

	// Input fields
	CEdit m_instrumentID_input;
	CEdit m_substanceName_input;
	CEdit m_nominalTemp_input;
	CEdit m_meassuredTemp_input;

	// DropDowns
	CComboBox m_instrumentID_dropDown;
	CComboBox m_substanceName_dropDown;
	CComboBox m_substanceForList_dropDown;

	// Lists
	CListCtrl m_listSubstances;

	// Buttons
	CButton m_buttonAdd;
	CButton m_buttonRemove;
	CButton m_buttonUpdate;

	// Plot area
	CRect m_plotRect;
	CRect m_equationRect;
	CRect m_alphaBetaRect;

	// List of instruments and their Substances
	InstrumentsContainer m_instruments;

	// List of substances names for List DropDown
	SubstanceNamesContainer m_substancesNames;

public:
	
	/*
		Method used for drawing the plot and generating equation and alhpaBeta texts
	*/
	virtual void OnDraw(CDC* pDC);

	/*
		Method which sets the initial app interface
	*/
	virtual void OnInitialUpdate();
	
protected:
	
	/*
		Method used to set app's background color
	*/
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	/*
		Method to makie Add button react to Enter key
	*/
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	/*
		Callback from Add button
	*/
	afx_msg void OnAddSubstance();

	/*
		Callback from predefined substances dropdown
	*/
	afx_msg void OnCbnSelchangeSubstanceCombo();

	/*
		Callback from substances for list dropdown
	*/
	afx_msg void OnCbnSelchangeSubstanceListCombo();

	/*
		Callback from instrument id's dropdown
	*/
	afx_msg void OnCbnSelchangeInstrumentIdCombo();

	/*
		Callback from Update button
	*/
	afx_msg void OnUpdateSubstance();

	/*
		Callback from Remove button
	*/
	afx_msg void OnRemoveSubstance();

	/*
		Method to refresh the substances table
	*/
	void RefreshSubstanceTable();

	/*
		Method to refresh a dropdown holding substances to display in table and on plot
	*/
	void RefreshSubstanceListCombo();

	/*
		Method to refresh instrument id's dropdown
	*/
	void RefreshInstrumentIdCombo();

	/*
		Method to get instrumant id and substance name from table (on select)
	*/
	bool GetSubstanceListElement(int& instrumentId, CString& selectedSubstanceName);

	DECLARE_MESSAGE_MAP()
};

