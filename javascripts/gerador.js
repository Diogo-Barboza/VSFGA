function gerarTreino() {
    const selecionados = Array.from(document.querySelectorAll('#treino-form input[type="checkbox"]:checked'))
      .map(cb => cb.value);
  
    const treinos = {
      peito: `
  ### Peito
  - Supino reto Máquina Articulada (ou barra) – 5x15-12-10-10-8
  - Supino inclinado Maquina Articulada – 4x12-10-10-10
  - Pullover com halter – 3x12-15
  - Crossover (cabo polia alta) – 3x12-15
      `,
      triceps: `
  ### Tríceps
  - Tríceps pulley (barra reta) – 4x8-10
  - Tríceps testa (Barra W ou Polia Unilateral) – 3x15-18
  - Tríceps Francês (Polia ou Halter) – 3x15-18
      `,
      costas: `
  ### Costas
  - Barra fixa ou puxada frontal – 4x12-10-8-8
  - Remada curvada com barra – 4x8-10
  - Remada unilateral com halteres – 3x10-12
  - Pulldown (pegada neutra) – 3x12-15
      `,
      biceps: `
  ### Bíceps
  - Rosca na Polia Baixa – 4x10-12
  - Rosca Banco Scott (Unilateral) – 4x12-15
  - Bíceps Martelo com halteres – 4x10-12
      `,
      perna: `
  ### Pernas
  - Agachamento livre – 5x15-12-12-10-10
  - Cadeira flexora – 4x15-12-12-12
  - Cadeira extensora – 3x15
  - Stiff – 3x12-15
  - Panturrilha (em pé ou leg press) – 5x15-20
      `,
      ombro: `
  ### Ombro, Trapézio e Abdômen
  - Desenvolvimento (barra/halteres) – 4x8-10
  - Elevação lateral com halteres – 3x12-15
  - Elevação frontal (halteres/corda) – 3x12-15
  - Crucifixo inverso (máquina/banco) – 3x12-15
  - Encolhimento com barra – 4x12-15
  - Remada alta com barra ou halteres – 3x10-12
  - Abdôminal Cruzado – 4x15-20
      `
    };
  
    let resultado = '';
    selecionados.forEach(musculo => {
      resultado += treinos[musculo] || '';
    });
  
    const container = document.getElementById('resultado-treino');
    container.innerHTML = `<div class="gerado">${resultado || 'Nenhuma opção selecionada.'}</div>`;
  }
  