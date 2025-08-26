var alunos = ['Leonardo', 'Kathelyn', 'Yasmin'];
let valores = [8, 1, 7, 4, 2, 9];
valores.sort()

let resultado = document.getElementById("resultado");
let resultado_valores = document.getElementById("resultado_valores");
let valores_1 = document.getElementById("valores_1");
let valores_2 = document.getElementById("valores_2");

// Caixinhas fixas
resultado.innerHTML = `
<div class="caixa">Aluno escolhido: <b>${alunos[2]}</b></div>
<div class="caixa">Lista de valores: <b>${valores.join(", ")}</b></div>
`;
// Criando caixinhas para cada valor usando o for 
for (let pos = 0; pos < valores.length; pos++) {
    resultado_valores.innerHTML += `<div class="caixa"><br>A posição ${pos} tem o valor ${valores[pos]}</div>`;
    } 


//Modelo mais trabalhoso porém bom.
for (let pos = 0; pos < valores.length; pos++) {
    valores_1.innerHTML += `<div id="valores_1">A posição ${pos} tem o valor ${valores[pos]}</div>`;
    } 

// Maneira  mais rapida de se fazer
for(let pos in valores){
    valores_2.innerHTML += `<br>A posição ${pos} tem o valor ${valores[pos]}`;
}