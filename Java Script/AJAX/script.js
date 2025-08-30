// Console interno
const consoleInterno = document.getElementById("console-messages");
function logConsole(msg) {
    const p = document.createElement("p");
    p.textContent = msg;
    consoleInterno.appendChild(p);
    consoleInterno.scrollTop = consoleInterno.scrollHeight;
}

// Manipulação da área de testes
const areaTeste = document.getElementById("area-teste");
const botaoLimpar = document.getElementById("limpar");

botaoLimpar.addEventListener("click", () => {
    areaTeste.innerHTML = "<p>Área limpa. Coloque seu HTML de teste aqui</p>";
    logConsole("Área de testes limpa.");
});

// Exemplo: adicionar botão e imagem dinamicamente
document.addEventListener("DOMContentLoaded", () => {
    const botao = document.createElement("button");
    botao.textContent = "Clique para buscar imagem de cachorro";
    botao.className = "btn btn-primary mt-3";

    const img = document.createElement("img");
    img.alt = "Cachorro";
    img.style.maxWidth = "300px";
    img.className = "img-fluid rounded mt-3 d-block mx-auto";

    botao.addEventListener("click", () => {
        fetch("https://dog.ceo/api/breeds/image/random")
            .then(res => res.json())
            .then(data => {
                img.src = data.message;
                logConsole("Imagem de cachorro carregada!");
            })
            .catch(err => logConsole("Erro: " + err));
    });

    areaTeste.appendChild(botao);
    areaTeste.appendChild(img);
});
