function sortByPower(pair1, pair2){
	if(pair1.val < pair2.val) return 1;
	if(pair1.val > pair2.val) return -1;
	return 0;
}

function getHitsDetail(bigHits, powers){
	let n = powers.length;
	let power_idx = [];
	let big = [], small = [], ans = [], req_pow = bigHits;
	
	for(let i = 0; i<n; i++){
		const curr_power_idx = {'val': powers[i], 'id': i+1};
		power_idx.push(curr_power_idx);
	}
	
	power_idx.sort(sortByPower);
	n = power_idx.length;
	for(let i=0; i<n && i<bigHits; i++){
	    const curr_id = power_idx[i].id;
	    big.push(curr_id);
	}
	
	for(let i=bigHits; i<n; i++){
	    const curr_id = power_idx[i].id;
	    req_pow += power_idx[i].val;
	    small.push(curr_id);
	}
	
	if(big.length == 0) big.push(-1);
	if(small.length == 0) small.push(-1);
	ans.push(req_pow);
	
	big.sort();
	small.sort();
	
	return [ans,big,small];
}


const big_hits = 0;
const arr = [1,5,2,4,3,6,7];
console.log(getHitsDetail(big_hits,arr));

