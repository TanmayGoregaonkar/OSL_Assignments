#!/bin/bash
#Name:Tanmay Deepak Goregaonkar
#Batch:L-10     Roll_No:33227
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CREATE FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

CREATE() 
{ 
	echo -e "Enter Name of the file:"
	read entered_file

	# Checking if file already exists
	search=`ls | grep $entered_file | wc -l` 
	
	if (( $search > 0 ))
	then
		file_name=$entered_file
		echo -e "Selected file named: $file_name "
	else
		file_name=$entered_file
		touch $file_name.txt
		echo -e "Created file named: $file_name "
		 
		echo -e "MOVIEID|MOVIENAME|MOVIETYPE"  >> $file_name.txt

	fi
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ADD FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ADD() 
{ 
	if [ -z $file_name ]  # checks if file length is zero
	then
		echo -e "Please create or select file first before adding contents!!!!"
	
	else  	
		echo -e "Enter Movie ID:"
		read MovieID
		
		echo -e "Name of the Movie:"
		read MovieName
		
		echo -e "Type of Movie:"
		read MovieType
		
		echo -e "$MovieID|$MovieName|$MovieType"   >> $file_name.txt
	fi
}
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DISPLAY FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

DISPLAY()
{
	echo -e "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
	cat $file_name.txt | column -t -s "|"
	echo -e "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DELETE FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

DELETE() 
{ 
	echo -e "Enter the CaseID which is to be deleted:"
	read Delete_CaseID
	
	flag=`cat $file_name.txt | grep $Delete_CaseID | wc -l`
	
	if [ $flag -eq 1 ] #checking valid CaseID
	then 
		deleted_item=`cat $file_name.txt | grep $Delete_CaseID`
		sed -i "/^$Delete_CaseID/d" $file_name.txt
		    # Deleting CaseID
		
		echo -e "Record Deleted Successfuly\n Record: $deleted_item"
	
	else
		echo -e "Entered MovieID doesn't exist!!"
	fi
}
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MODIFY FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

MODIFY()
{
	echo -e "Enter the CaseID to modify the Case Entry:"
	read modify_CaseID
	check_flag=`cat $file_name.txt | grep $modify_CaseID | wc -l`
	if [ $check_flag -eq 0 ]
	then
		echo -e "Entered MovieID doesn't exist, Check Again!!"
	else
		original_line=`cat $file_name.txt | grep $modify_CaseID`
		
		echo -e "Enter the following values to modify the file:"
		
		read -p "Enter MovieID:" New_Complainer
		read -p "Enter Name of Movie:" New_Accused 
		read -p "Enter Type of Movie:" New_Reason 

		
		
		
		new_line="$modify_CaseID|$New_Complainer|$New_Accused|$New_Reason"
		
		sed -i "s/$original_line/$new_line/" $file_name.txt
		
		echo "Changes done!"
	fi	
}
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAIN CODE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


# MENU
echo -e "MOVIE DATABASE"
echo -e "Select an Operation (Enter f to exit)\nEnter : \n  a to Create New file or Select Existing File\n  b to ADD Entries to File \n  c to Display File \n  d to Delete Case Content\n  e to Modify File \n  f to Exit "
read Operation


while [ $Operation != f ]
do

	
	
	case $Operation in  # CASE FOR VARIOUS OPTIONS ; FUNCTIONS CALL FOR RESPECTIVE OPTIONS
		
		a)
		CREATE 
		;;
		
		b)
		ADD
		;;
		
		c)
		DISPLAY
		;;
		
		d)
		DELETE 
		;;
		
		e)
		MODIFY
		;;
		
		
		*)   # ERROR MESSAGE FOR IRRELEVANT ENTRIES
		echo "Invalid Entry!!!"
		;;
		
	
	esac
	echo -e "Select an Operation (Enter f to exit)\nEnter : \n  a to Create New file or Select Existing File\n  b to ADD Entries to File \n  c to Display File \n  d to Delete Case Content\n  e to Modify File \n  f to Exit "
	read Operation

done
