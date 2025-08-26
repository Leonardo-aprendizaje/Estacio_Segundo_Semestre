var alunos = ['Alex', 'Ana', 'João'];
let valores = [8, 1, 7, 4, 2, 9];

let resultado = document.getElementById("resultado");

// Caixinhas fixas
resultado.innerHTML = `
<div class="caixa">Aluno escolhido: <b>${alunos[1]}</b></div>
<div class="caixa">Lista de valores: <b>${valores.join(", ")}</b></div>
`;

let resultado_valores = document.getElementById("resultado_valores");

// Criando caixinhas para cada valor usando o for
for (let pos = 0; pos < valores.length; pos++) {
    resultado_valores.innerHTML += `
        <div class="caixa">A posição ${pos} tem o valor ${valores[pos]}</div>
    `;
}
