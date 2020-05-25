library(shiny)

shinyUI(fluidPage(
  titlePanel(title = h4("Iris Dataset", align = "center")),
  sidebarLayout(
    sidebarPanel(
      selectInput(inputId = "var",
                  label = "1. Select the varialbe from the iris dataset",
                  choices = c("Sepal.Length" = 1, "Sepal.Width" = 2,
                              "Petal.Length" = 3, "Petal.Width" = 4),
                  selected = 1),
      br(),
      sliderInput(inputId = "bins",
                  label = "2. Select the number of BINs for histogram",
                  min = 5, max = 25, value = 15),
      br(),
      radioButtons(inputId = "color",
                   label = "3. Select the color of histogram",
                   choices = c("Green", "Red", "Yellow"),
                   selected = "Green"),
      br(),
      radioButtons(inputId = "download_type",
                   label = "Select the file type",
                   choices = c("png", "pdf"))
    ),
    mainPanel(
      textOutput("var"),
      textOutput("bins"),
      textOutput("color"),

      plotOutput("my_hist"),
      downloadButton(outputId = "down",
                     label = "Download the plot")
    )
  )
))
