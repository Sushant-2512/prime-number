const { isPrime } = require("../../backend/build/Release/addon.node");

getValue = function (event) {
  event.preventDefault();
  var val = document.getElementById("num").value;

  const res = isPrime(parseInt(val));
  if (res === 1) alert("This Number is prime Number.");
  else alert("This Number is Not Prime Number.");
};
