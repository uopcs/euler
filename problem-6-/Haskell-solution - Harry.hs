six (x:xs) = sum . map(^2)   		

six2 (x:xs)=  map(^2) . sum 	

sixfinal = six2 - six
