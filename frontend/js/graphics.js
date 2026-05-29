function countJudgerCode(data, folder) {
  const contentUnique = [...new Set(data.map((item) => item[folder]))];

  countContent = {};

  contentUnique.forEach((value) => {
    countContent[value] = 0;
  });

  data.forEach((row) => {
    countContent[row[folder]]++;
  });

  return countContent;
}

function graphicBuild(urlData, title) {
  fetch(urlData)
    .then((response) => {
      if (!response.ok) {
        throw new Error("Não existe o arquivo!!" + response.status);
      }
      return response.json();
    })
    .then((data) => {
      const statusTheHuxley = countJudgerCode(data, "status_the_huxley");
      const statusLLMJudger = countJudgerCode(data, "status_judger");

      const xArray = Object.keys(statusTheHuxley);

      const yArrayTheHuxley = Object.values(statusTheHuxley);
      const yArrayLLM = xArray.map((key) => statusLLMJudger[key] || 0);

      const dataGraphics = [
        {
          x: xArray,
          y: yArrayTheHuxley,
          type: "bar",
          name: "The Huxley",
          orientation: "v",
          marker: { color: "rgba(0,0,255,0.6)" },
          text: yArrayTheHuxley,
          textposition: "auto",
          hoverinfo: "y",
        },
        {
          x: xArray,
          y: yArrayLLM,
          type: "bar",
          name: "LLM Judger",
          orientation: "v",
          marker: { color: "rgba(255,0,0,0.6)" },
          text: yArrayLLM,
          textposition: "auto",
          hoverinfo: "y",
        },
      ];

      const layout = {
        title: title,
        barmode: "group",
      };

      Plotly.newPlot("graphic-the-huxley-simulation", dataGraphics, layout);
    })
    .catch((e) => {
      console.error("Ocorreu um erro: ", e);
    });
}

const gpt = document.getElementById("btn-gpt5-4-nano");
const gemini = document.getElementById("btn-gemini-3-flash");

gpt.addEventListener("click", () => {
  if (
    gpt.classList.contains("bg-gray-200") &&
    gpt.classList.contains("text-gray-700")
  ) {
    gpt.classList.remove("bg-gray-200", "text-gray-700");
    gpt.classList.add("bg-blue-600", "text-white");
    gemini.classList.remove("bg-blue-600", "text-white");
    gemini.classList.add("bg-gray-200", "text-gray-700");
    console.log("Sou gpt");
  }
});

gemini.addEventListener("click", () => {
  if (
    gemini.classList.contains("bg-gray-200") &&
    gemini.classList.contains("text-gray-700")
  ) {
    gemini.classList.remove("bg-gray-200", "text-gray-700");
    gemini.classList.add("bg-blue-600", "text-white");
    gpt.classList.remove("bg-blue-600", "text-white");
    gpt.classList.add("bg-gray-200", "text-gray-700");
    console.log("Sou gemini");
  }
});

const urlData =
  "/create-code-and-judge-code-with-llms/database/output/json/simulation_the_huxley_gpt_5_4_nano.json";

graphicBuild(
  urlData,
  "Gemini 3 Flash Preview no The Huxley e o GPT 5.4 Nano simulando o The Huxley",
);
