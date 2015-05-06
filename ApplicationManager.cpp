#include "ApplicationManager.h"
#include "Actions\AddSmplAssign.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Actions\Select.h"
#include "Move.h"
#include "Copy.h"
#include "Cut.h"
#include "Delete.h"
#include "Edit.h"
#include "MultiSelect.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	StatCount = 0;
	ConnCount = 0;
	pSelectedStat = NULL;	//no Statement is selected yet
	
	//Create an array of Statement pointers and set them to NULL		
	for(int i=0; i<MaxCount; i++)
	{
		StatList[i] = NULL;	
		ConnList[i] = NULL;
	}
}
//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to ActioType, create the corresponding action object
	switch (ActType)
	{
		case ADD_SMPL_ASSIGN:
			pAct = new AddSmplAssign(this);
			break;

		case ADD_END:
			///create AddCondition Action here

			break;

		case ADD_SELECT:
			///create Select Action her
			pAct = new Select(this);
			break;
	//	case Move:
		//	pAct = new Move(this);
			//break;
		case EDIT:
			pAct = new Edit(this);
			break;

		case MULTI_SELECT:
			pAct = new MultiSelect(this);
			break;
		case DEL:
			///create Exit Action here
			pAct = new Delete(this);
			break;
		case MOVE:
			pAct = new Move(this);
			break;
		case COPY:
			pAct = new Copy(this);
			break;
		case CUT:
			pAct = new Cut(this);
			break;
		case STATUS:
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
	}
}
//==================================================================================//
//						Statements Management Functions								//
//==================================================================================//
//Add a statement to the list of statements
void ApplicationManager::AddStatement(Statement *pStat)
{
	if(StatCount < MaxCount)
		StatList[StatCount++] = pStat;
}
/////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::DeleteStatement(Statement* p) {
	for (int i = 0; i<MaxCount; i++)
		if (StatList[i] == p) {

			StatList[i] = StatList[StatCount-1];

			StatList[StatCount-1] = nullptr;

			StatCount--;

			break;
		}
}
////////////////////////////////////////////////////////////////////////////////////
Statement *ApplicationManager::GetStatement(Point P) const
{
	//If this point P(x,y) belongs to a statement return a pointer to it.
	//otherwise, return NULL
	for (int i = 0; i<MaxCount; i++)
	{
		if (StatList[i]->Within(P))
		{
			return StatList[i];
		}
	}

	///Add your code here to search for a statement given a point P(x,y)	

	return NULL;
}
Statement** ApplicationManager::GetAllSelectedStatements()
{
	for (int i = 0; i < MaxCount; i++)
	{
		AllSelectedStatments[i] = NULL;
	}
	int j = 0;
	for (int i = 0; i<MaxCount; i++)
	{
		if (StatList[i]->IsSelected()==true)
		{
			AllSelectedStatments[j] = StatList[i];
			j++;
		}
		
	}
	return AllSelectedStatments;
}
////////////////////////////////////////////////////////////////////////////////////
//Returns the selected statement
Statement *ApplicationManager::GetSelectedStatement() const
{	return pSelectedStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedStatement(Statement *pStat)
{	pSelectedStat = pStat;	}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	//Draw all statements
	for(int i=0; i<StatCount; i++)
		StatList[i]->Draw(pOut);
	
	//Draw all connections
	for(int i=0; i<ConnCount; i++)
		ConnList[i]->Draw(pOut);

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<StatCount; i++)
		delete StatList[i];
	for(int i=0; i<StatCount; i++)
		delete ConnList[i];
	delete pIn;
	delete pOut;
}