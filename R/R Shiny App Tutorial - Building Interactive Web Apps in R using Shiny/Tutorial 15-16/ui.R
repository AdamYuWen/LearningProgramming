library(shiny)

shinyUI(fluidPage(
  titlePanel(title = h4("Tutorial 15 & 16", align = "center")),

  sidebarLayout(
    sidebarPanel(
      # By default, multiple is FALSE.
      fileInput(inputId = "file",
                label = "Upload the file",
                multiple = TRUE),
      helpText("Default max. file size is 5MB"),

      tags$hr(),
      h5(helpText("Select the read.table parameters below")),

      # The return for checkbox is TRUE or FALSE.
      checkboxInput(inputId = "header", label = "Header", value = FALSE),
      checkboxInput(inputId = "stringAsFactors",
                    label = "stringAsFactors", value = FALSE),

      br(),
      # Set the values here, instead of in server.R.
      radioButtons(inputId = "separator",
                   label = "Separator",
                   choices = c("Comma" = ",",
                               "Semicolon" = ";",
                               "Tab" = "\t",
                               "Space" = " "),
                   selected = ","), # It needs to be ",". "Comma" doesn't work.

      uiOutput("select_file"),

      # Add an image
      h5("Powered by", tags$img(src = "RStudio-Ball.png",
                                height = 50,
                                width = 50)),

      tags$hr(),
      fileInput(inputId = "zip_file",
                label = "Upload zip file",
                accept = ".zip"),

      actionButton(inputId = "unzip",
                   label = "Unzip Files")
    ),

    mainPanel(
      uiOutput("tab")
    )
  )
))
