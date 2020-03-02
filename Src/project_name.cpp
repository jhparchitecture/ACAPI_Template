// *****************************************************************************
// Source code for the project_name Add-On
// API Development Kit 22; Mac/Win
//
// Namespaces:			Contact person:
//		-None-
//
// [SG compatible] - Yes
// *****************************************************************************

#include 	"APIEnvir.h"

// ---------------------------------- Includes ---------------------------------

#include	"ACAPinc.h"					// also includes APIdefs.h
#include	"project_nameResIDs.hpp"


// ---------------------------------- Types ------------------------------------


// ---------------------------------- Variables --------------------------------



// -----------------------------------------------------------------------------

GSErrCode	__ACENV_CALL	MenuCommandHandler (const API_MenuParams *params)
{
	return ACAPI_CallUndoableCommand("project_name Menu Command", [&]() -> GSErrCode {

		switch (params->menuItemRef.menuResID)
		{
			case PROJECT_NAME_MENU_STRINGSID: {

				//Execute Menu option code:

				/* switch (params->menuItemRef.itemIndex)
				{
					//Execute Menu suboptions
				} */
			}
		}

		return NoError;
	});
}		
// MenuCommandHandler



// =============================================================================
//
// Required functions
//
// =============================================================================


//------------------------------------------------------
// Dependency definitions
//------------------------------------------------------
API_AddonType	__ACENV_CALL	CheckEnvironment (API_EnvirParams* envir)
{
	RSGetIndString (&envir->addOnInfo.name, PROJECT_NAME_ABOUT_STRINGSID, 1, ACAPI_GetOwnResModule ());
	RSGetIndString (&envir->addOnInfo.description, PROJECT_NAME_ABOUT_STRINGSID, 2, ACAPI_GetOwnResModule ());

	return APIAddon_Normal; 
	//return APIAddon_Preload; //!Change to APIAddon_Preload to allow listening for events!
}		
// CheckEnvironment


//------------------------------------------------------
// Interface definitions
//------------------------------------------------------
GSErrCode	__ACENV_CALL	RegisterInterface (void)
{
	GSErrCode err = NoError;
	err = ACAPI_Register_Menu (PROJECT_NAME_MENU_STRINGSID, 0, MenuCode_UserDef, MenuFlag_Default);


	return NoError;
}		
// RegisterInterface


// -----------------------------------------------------------------------------
// Initialize
//		called after the Add-On has been loaded into memory
// -----------------------------------------------------------------------------

GSErrCode __ACENV_CALL	Initialize (void)
{
	GSErrCode err = ACAPI_Install_MenuHandler (PROJECT_NAME_MENU_STRINGSID, MenuCommandHandler);
	
	return err;
}		
// Initialize


// -----------------------------------------------------------------------------
// FreeData
//		called when the Add-On is going to be unloaded
// -----------------------------------------------------------------------------

GSErrCode __ACENV_CALL	FreeData (void)
{
	return NoError;
}		
// FreeData
