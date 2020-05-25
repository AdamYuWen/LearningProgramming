library(shiny)

shinyUI(fluidPage(
  titlePanel(title = h4("Tutorial 11", align = "center")),

  sidebarLayout(
    sidebarPanel(
      selectInput(inputId = "dataset",
                  label = "Select the dataset",
                  choices = c("iris", "mtcars", "trees")),
      br(),
      helpText("Select the download format"),
      radioButtons(inputId = "type",
                   label = "Format type:",
                   choices = c("Excel (CSV)", "Text (TSV)",
                               "Text (Space Separated)", "Doc")),
      br(),
      helpText("Click on the download button to download the dataset
               observations"),
      # The download button is a output.
      downloadButton(outputId = "download_data",
                     label = "Download")
    ),

    mainPanel(
      # It is for showing the table.
      tableOutput("table")
    )
  )
))
