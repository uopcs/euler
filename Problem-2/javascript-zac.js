var f = [];
f[0] = 1;
f[1] = 1;
var total = 2;
for(var i = 2; i < 4000000; i++){
	f[i] = f[i - 1] + f[i - 2];
	if(f[i] % 2 == 0) total += f[i];
}
console.log(total);