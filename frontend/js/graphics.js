const urlData =
  "/create-code-and-judge-code-with-llms/database/output/json/simulation_the_huxley_gpt_5_4_nano.json";

fetch(urlData)
  .then((response) => {
    if (!response.ok) {
      throw new Error("Não existe o arquivo!!" + response.status);
    }
    return response.json();
  })
  .then((data) => {
    console.log("Dados completos: ", data);

    const statusCheck = [...new Set(data.map(item => item.status_the_huxley))];
    
    statusTheHuxley = {};
    
    statusCheck.forEach(value => {
        statusTheHuxley[value] = 0;
    });

    data.forEach(row => {
        statusTheHuxley[row.status_the_huxley]++;
    });

    console.log(statusTheHuxley);
  })
  .catch((e) => {
    console.error("Ocorreu um erro: ", e);
  });