var selectedRow=null

function onFormSubmit(e){
    event.preventDefault();
    var formData=readFormData();
    if(selectedRow==null){
        insertNewRecord(formData);
    }
    else{
        updateRecord(formData);
    }
    resetForm();
}

function readFormData(){
    var formData={};
    formData["regno"]=document.getElementById("regno").value;
    formData["name"]=document.getElementById("name").value;
    formData["branch"]=document.getElementById("branch").value;
    formData["cgpa"]=document.getElementById("cgpa").value;
    return formData;
}

function insertNewRecord(data){
    var table=document.getElementById("storeList").getElementsByTagName("tbody")[0];
    var newRow=table.insertRow(table.length);
    cell1=newRow.insertCell(0);
    cell1.innerHTML=data.regno;
    cell2=newRow.insertCell(1);
    cell2.innerHTML=data.name;
    cell3=newRow.insertCell(2);
    cell3.innerHTML=data.branch;
    cell4=newRow.insertCell(3);
    cell4.innerHTML=data.cgpa;
    cell4=newRow.insertCell(4);
    cell4.innerHTML=`<button onclick="onEdit(this)">Edit</button><button onClick="onDelete(this)">Delete</button>`;
}

function onEdit(td){
    selectedRow=td.parentElement.parentElement;
    document.getElementById("regno").value=selectedRow.cells[0].innerHTML;
    document.getElementById("name").value=selectedRow.cells[1].innerHTML;
    document.getElementById("branch").value=selectedRow.cells[2].innerHTML;
    document.getElementById("cgpa").value=selectedRow.cells[3].innerHTML;
}

function updateRecord(formData){
    selectedRow.cells[0].innerHTML=formData.regno;
    selectedRow.cells[1].innerHTML=formData.name;
    selectedRow.cells[2].innerHTML=formData.branch;
    selectedRow.cells[3].innerHTML=formData.cgpa;
}

function onDelete(td){
    if(confirm("Do you want to delete this record?")){
        row=td.parentElement.parentElement;
        document.getElementById("storeList").deleteRow(row.rowIndex);
        resetForm();
    }
}

function resetForm(){
    document.getElementById("regno").value="";
    document.getElementById("name").value="";
    document.getElementById("branch").value="";
    document.getElementById("cgpa").value="";
    selectedRow=null;
}