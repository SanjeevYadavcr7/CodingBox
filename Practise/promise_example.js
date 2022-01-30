const promiseA = Promise.resolve('Promise A');
const promiseB = Promise.resolve('Promise B');
const promiseC = Promise.resolve('Promise C');

const callPromises = async () => {
	for(let promise of [promiseA,promiseB,promiseC]) {
		try{
			const res = await promise;
			console.log(res);
		}
		catch(err){
			console.log(err.message);
		}
	}
}

callPromises();
