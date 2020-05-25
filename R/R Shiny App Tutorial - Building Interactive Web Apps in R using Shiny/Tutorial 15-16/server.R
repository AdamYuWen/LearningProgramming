library(shiny)

# Change the upload limit to infinity.
# options(shiny.maxRequestSize = 9 * 1024^2)

shinyServer(function(input, output) {
  # Select input file ----------
  output$select_file <- renderUI({
    if (is.null(input$file)) {
      return()
    } else {
      list(hr(),
           selectInput("select", "Select a file",
                       choices = input$file$name))
    }
  })

  # Generate outputs ----------
  # User input parameters for read.table.
  df <- reactive({
    # If there is no input file, don't read it.
    if (is.null(input$file)) {
      return()
    } else {
      # Read data based on selection
      read.table(file = input$file$datapath[input$file$name == input$select],
                 sep = input$separator,
                 header = input$header,
                 stringsAsFactors = input$stringAsFactors)
    }
  })

  output$file_df <- renderTable({
    if (is.null(input$file)) {
      return()
    } else {
       input$file
    }
  })

  output$data <- renderTable({
    if (is.null(input$file)) {
      return()
    } else {
      df()
    }
  })

  output$summary <- renderTable({
    if (is.null(input$file)) {
      return()
    } else {
      summary(df())
    }
  })

  # Combine two data frames
  output$datamerge <- renderTable({
    if (is.null(input$file)) {
      return()
    } else {
      num_file <- nrow(input$file)

      csv <- list()
      for (i in 1:num_file) {
        csv[[i]] <- read.csv(input$file$datapath[i])
      }
      do.call(rbind, csv)
    }
  })

  # Action for actionButton ----------
  # For actionButton, it will act when the button is clicked.
  observeEvent(input$unzip,
               output$zipped <- renderTable({
                 unzip(input$zip_file$datapath)
               }))

  # Show outputs ---------
  output$tab <- renderUI({
    if (is.null(input$file)) {
      # Add an image, when the file is not loaded.
      # The png file has to be in a "www" folder.
      h5("Kobe video", tags$video(src = "kobe_video.mp4",
                                  type = "video/mp4",
                                  width = "350px",
                                  height = "350px",
                                  controls = "controls"))
    } else {
    tabsetPanel(type = "tab",
                tabPanel(title = "About file", tableOutput("file_df")),
                tabPanel(title = "Data", tableOutput("data")),
                tabPanel(title = "Summary", tableOutput("summary")),
                tabPanel(title = "Merge", tableOutput("datamerge")),
                tabPanel(title = "Unzip", tableOutput("zipped")),
                tabPanel(title = "Reference",
                         tags$iframe(style = "height: 800px;
                                              width: 100%;
                                              scrolling = yes",
                                     src = "shiny-cheatsheet.pdf")))
    }
  })
})
