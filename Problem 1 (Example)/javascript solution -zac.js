for(var i = 0, total = 0; i < 1000; i++){
	if(i % 3 == 0 || i % 5 == 0){
		total+=1;
	}
}
console.log(total);