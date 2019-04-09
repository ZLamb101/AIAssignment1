cls
@echo off


@echo ====================================================================================================================================================
@echo EXPERIMENT (2)
@echo ====================================================================================================================================================
@echo INIT_STATE_#2: 364058271     GOAL STATE: 123804765
@echo ====================================================================================================================================================
@echo  ALGORITHM		         PATH_LENGTH	STATE_EXPANSIONS    MAX_QLENGTH	 RUNNING_TIME  DELETIONS_MIDDLE_HEAP ATTEMPTED_REEXPANSIONS
@echo ====================================================================================================================================================
set INIT_STATE = "364058271"
set GOAL_STATE = "123804765"


main.exe "batch_run" "Breadth_First_Search"  "364058271" "123804765"
main.exe "batch_run" "Breadth_First_Search_VList"  "364058271" "123804765"

main.exe "batch_run" "PDS_No_VList" 		"364058271" "123804765"
main.exe "batch_run" "uniformcost_expandedlist" 	"364058271" "123804765"
  
main.exe "batch_run" "aStar_ExpList_MisplacedTiles"     "364058271" "123804765"
main.exe "batch_run" "aStar_ExpList_Manhattan" 			"364058271" "123804765"





@echo ====================================================================================================================================================
@echo EXPERIMENT (3)
@echo ====================================================================================================================================================
@echo INIT_STATE_#3: 281463075     GOAL STATE: 123804765
@echo ====================================================================================================================================================
@echo  ALGORITHM		         PATH_LENGTH	STATE_EXPANSIONS    MAX_QLENGTH	 RUNNING_TIME  DELETIONS_MIDDLE_HEAP ATTEMPTED_REEXPANSIONS
@echo ====================================================================================================================================================
set INIT_STATE = "281463075"
set GOAL_STATE = "123804765"

main.exe "batch_run" "Breadth_First_Search"  "281463075" "123804765"
main.exe "batch_run" "Breadth_First_Search_VList"  "281463075" "123804765"

main.exe "batch_run" "PDS_No_VList" 		"281463075" "123804765"
main.exe "batch_run" "uniformcost_expandedlist" 	"281463075" "123804765"

main.exe "batch_run" "aStar_ExpList_MisplacedTiles"     "281463075" "123804765"
main.exe "batch_run" "aStar_ExpList_Manhattan" 			"281463075" "123804765"




@echo nothing follows.

