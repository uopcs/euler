var f = [];
f[0] = f[1] = 1;
var total = 0;
var i = 2;
while(total <= 4000000){
	f[i] = f[i - 1] + f[i - 2];
	if(f[i] % 2 == 0) total += f[i];
	i++;
}
console.log("zac: " + total);